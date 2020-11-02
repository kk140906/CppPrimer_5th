/**
 * Exercise 15.41 重写Query类，使用内置指针而不是shared_ptr
 */


#include <iostream>

#include <set>
#include <memory>
#include <string>

#include "../common/header/text_query.h"
#include "../common/header/text_query_result.h"

namespace exercise1541 {

/**
 * 通过Query这个接口类去调用所有的接口，隐藏了所有的实现
 * 不期望用户直接使用QueryBase及其派生类应该将其成员都定义为private或者protected
 * 声明为private后Query需要调用Query_base执行不同的对象的eval和rep函数，故将其声明为友元
 */
    class Query;

    class QueryBase {
        friend class Query;

    protected:
        using line_num = std::size_t;
        using query_values = std::pair<std::string, std::set<line_num>>;

        virtual ~QueryBase() = default;

    private:
        virtual TextQueryResult eval(TextQuery &tq) const = 0;

        virtual std::string rep() const = 0;
    };


/*
 * Query类是一个接口类，对外提供查询的所有接口
 */
    class Query {
        friend Query operator&(const Query &lhs, const Query &rhs);

        friend Query operator|(const Query &lhs, const Query &rhs);

        friend Query operator~(const Query &rhs);

        friend std::ostream &operator<<(std::ostream &os, const Query &rhs);

    public:
        // 构造函数，接受一个string对象，绑定WordQuery对象到sp_qb_
        Query(const std::string &word);

        // Query对象的拷贝行为类似指针
        Query(const Query &rhs) : qb_(rhs.qb_), use_(rhs.use_) {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            ++*use_;
        }

        Query(Query &&rhs) : qb_(std::move(rhs.qb_)), use_(std::move(rhs.use_)) {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            ++*use_;
        }

        Query &operator=(const Query &rhs) {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            ++*rhs.use_;
            if (--*use_ == 0) {
                delete qb_;
                delete use_;
            }
            qb_ = rhs.qb_;
            use_ = rhs.use_;
            return *this;
        }

        Query &operator=(Query &&rhs) {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            ++*rhs.use_;
            if (--*use_ == 0) {
                delete qb_;
                delete use_;
            }
            qb_ = std::move(rhs.qb_);
            use_ = std::move(rhs.use_);
            return *this;
        }

        ~Query() {
            if (--*use_ == 0) {
                delete qb_;
                delete use_;
            }
        }

        // 根据动态绑定的对象执行对应的对象的eval操作
        TextQueryResult eval(TextQuery &q) const { return qb_->eval(q); }

        // 根据动态绑定的对象返回查询的字符串
        std::string rep() const { return qb_->rep(); }

    private:
        Query(QueryBase *qb) : qb_(qb), use_(new std::size_t(1)) {}

        // 参考Exercise13.27
        std::size_t *use_;
        QueryBase *qb_;
    };

/**
 * 单词查询，唯一一个实际的查询，与、或、非操作的最终查询都由此进行
 */
    class WordQuery : public QueryBase {

        friend class Query;

    private:

        WordQuery(const std::string &word) : word_(word) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

        TextQueryResult eval(TextQuery &tq) const override { return tq.query(word_); }

        std::string rep() const override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return word_;
        }

        std::string word_;
    };

/**
 * 取反查询是对一个Query对象进行操作
 */
    class NotQuery : public QueryBase {

        friend Query operator~(const Query &rhs);

    private:

        NotQuery(const Query &query) : query_(query) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

        TextQueryResult eval(TextQuery &tq) const override;

        std::string rep() const override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return "~(" + query_.rep() + ")";
        }

        Query query_;
    };

/**
 * 二元操作对象的抽象基类
 */
    class BinaryQuery : public QueryBase {

    protected:
        BinaryQuery(const Query &lhs, const Query &rhs, const std::string &op) :
                query_lhs_(lhs),
                query_rhs_(rhs),
                op_(op) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

        // rep比较容易实现，使其派生类可以直接继承基类的实现，避免代码重复
        std::string rep() const override {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return "(" + query_lhs_.rep() + " " + op_ + " " + query_rhs_.rep() + ")";
        };
        Query query_lhs_, query_rhs_;
        std::string op_;

    };

    class AndQuery : public BinaryQuery {

        friend Query operator&(const Query &lhs, const Query &rhs);

    private:
        AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }

        TextQueryResult eval(TextQuery &tq) const override;

    };

    class OrQuery : public BinaryQuery {

        friend Query operator|(const Query &lhs, const Query &rhs);

    private:
        OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }

        TextQueryResult eval(TextQuery &tq) const override;
    };


    Query::Query(const std::string &word) : qb_(new WordQuery(word)), use_(new std::size_t(1)) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }


    Query operator&(const Query &lhs, const Query &rhs) {
        return Query(new AndQuery(lhs, rhs));
    }


    Query operator|(const Query &lhs, const Query &rhs) {
        return Query(new OrQuery(lhs, rhs));
    }


    Query operator~(const Query &rhs) {
        return Query(new NotQuery(rhs));
    }

    std::ostream &operator<<(std::ostream &os, const Query &rhs) {
        os << rhs.rep();
        return os;
    }


    TextQueryResult AndQuery::eval(TextQuery &tq) const {
        auto result_lhs = query_lhs_.eval(tq);
        auto result_rhs = query_rhs_.eval(tq);
        std::set<line_num> result;
        std::set_intersection(result_lhs.begin(), result_lhs.end(), result_rhs.begin(), result_rhs.end(),
                              std::inserter(result, result.begin()));
        auto sp_result = std::make_shared<query_values>(query_values{rep(), result});
        return TextQueryResult(result_lhs.get_file(), sp_result, result_lhs.stream());
    }

    TextQueryResult OrQuery::eval(TextQuery &tq) const {
        auto result_lhs = query_lhs_.eval(tq);
        auto result_rhs = query_rhs_.eval(tq);
        std::set<line_num> result;
        std::set_union(result_lhs.begin(), result_lhs.end(), result_rhs.begin(), result_rhs.end(),
                       std::inserter(result, result.begin()));
        auto sp_result = std::make_shared<query_values>(query_values{rep(), result});
        return TextQueryResult(result_lhs.get_file(), sp_result, result_lhs.stream());

    }

    TextQueryResult NotQuery::eval(TextQuery &tq) const {
        auto result_rhs = query_.eval(tq);
        auto lines = result_rhs.get_file()->size();
        std::set<line_num> lines_set, result;
        for (std::size_t num = 0; num < lines; ++num) { lines_set.insert(num); }
        std::set_difference(lines_set.begin(), lines_set.end(), result_rhs.begin(), result_rhs.end(),
                            std::inserter(result, result.begin()));

        auto sp_result = std::make_shared<query_values>(query_values{rep(), result});
        return TextQueryResult(result_rhs.get_file(), sp_result, result_rhs.stream());
    }
}


using namespace exercise1541;
using namespace std;

int main() {
    string file("Pride_And_Prejudice.txt");
    TextQuery tq(file);
    Query q = Query("this") & Query("once") | Query("men");
    cout << q << endl;
    TextQueryResult result = q.eval(tq);
    result.print();
    return 0;
}

