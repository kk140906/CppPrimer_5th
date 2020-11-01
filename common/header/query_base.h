//
// Created by KK on 2020/10/29.
//

#ifndef C___PRIMER_EXERCISE_QUERY_BASE_H
#define C___PRIMER_EXERCISE_QUERY_BASE_H

#include <memory>
#include <string>

#include "text_query.h"
#include "text_query_result.h"

//#define NDEBUG

/*
 * 通过Query这个接口类去调用所有的接口，隐藏了所有的实现
 * 不期望用户直接使用QueryBase及其派生类应该将其成员都定义为private或者protected
 * 声明为private后Query需要调用Query_base执行不同的对象的eval和rep函数，故将其声明为友元
 */
class Query;

class QueryHistoriesLogger;


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

    // 根据动态绑定的对象执行对应的对象的eval操作
    TextQueryResult eval(TextQuery &q) const { return sp_qb_->eval(q); }

    // 根据动态绑定的对象返回查询的字符串
    std::string rep() const { return sp_qb_->rep(); }

private:
    Query(const std::shared_ptr<QueryBase> &q) : sp_qb_(q) {}

    // sp_qb_是指向抽象基类的智能指针，当指向派生类对象时会发生动态绑定
    std::shared_ptr<QueryBase> sp_qb_;
};

/*
 * 单词查询，唯一一个实际的查询，与、或、非操作的最终查询都由此进行
 */
class WordQuery : public QueryBase {

    friend class Query;

private:

    WordQuery(const std::string &word) : word_(word) {
#ifndef NDEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    }

    TextQueryResult eval(TextQuery &tq) const { return tq.query(word_); }

    std::string rep() const {
#ifndef NDEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        return word_;
    }

    std::string word_;
};


/*
 * 取反查询是对一个Query对象进行操作
 */
class NotQuery : public QueryBase {

    friend Query operator~(const Query &rhs);

private:

    NotQuery(const Query &query) : query_(query) {
#ifndef NDEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    }

    TextQueryResult eval(TextQuery &tq) const override;

    std::string rep() const override {

#ifndef NDEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        return "~(" + query_.rep() + ")";
    }

    Query query_;
};

/*
 * 二元操作对象的抽象基类
 */
class BinaryQuery : public QueryBase {

protected:
    BinaryQuery(const Query &lhs, const Query &rhs, const std::string &op) :
            query_lhs_(lhs),
            query_rhs_(rhs),
            op_(op) {
#ifndef NDEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    }

    // rep比较容易实现，使其派生类可以直接继承基类的实现，避免代码重复
    virtual std::string rep() const override {

#ifndef NDEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        return "(" + query_lhs_.rep() + " " + op_ + " " + query_rhs_.rep() + ")";
    };
    Query query_lhs_, query_rhs_;
    std::string op_;

};

class AndQuery : public BinaryQuery {

    friend Query operator&(const Query &lhs, const Query &rhs);

private:
    AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {
#ifndef NDEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    }

    TextQueryResult eval(TextQuery &tq) const override;

};

class OrQuery : public BinaryQuery {

    friend Query operator|(const Query &lhs, const Query &rhs);

private:
    OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {
#ifndef NDEBUG
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    }

    TextQueryResult eval(TextQuery &tq) const override;
};

/*
 * 查询历史记录器
 */

class QueryHistoriesLogger {
public:

    friend Query operator&(const Query &lhs, const Query &rhs);

    friend Query operator|(const Query &lhs, const Query &rhs);

    friend Query operator~(const Query &rhs);

    friend class Query;

    // 创建单例模式
    static QueryHistoriesLogger *CreatInstance() {
        if (!instance_) {
            instance_ = new QueryHistoriesLogger;
        }
        return instance_;
    }

    Query *GetQuery(std::size_t num) {
        return &*logger_[num];
    }

    void Print() {
        std::size_t num = 0;
        for (const auto &cl:logger_) {
            std::cout << "Query History " << num++ << " : " << cl->rep() << std::endl;
        }
    }

    void Clear() {
        if (!logger_.empty()) {
            logger_.clear();
        }
    }

private:
    void AddToLogger(Query &q) {
        logger_.push_back(std::make_shared<Query>(q));
    }

    std::vector<std::shared_ptr<Query>> logger_;
    static QueryHistoriesLogger *instance_;
};


#endif //C___PRIMER_EXERCISE_QUERY_BASE_H
