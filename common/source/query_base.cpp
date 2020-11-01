//
// Created by KK on 2020/10/29.
//

#define NDEBUG

#include <algorithm>
#include <iterator>
#include "../header/query_base.h"

QueryHistoriesLogger *QueryHistoriesLogger::instance_ = nullptr;

QueryHistoriesLogger *logger = QueryHistoriesLogger::CreatInstance();

Query::Query(const std::string &word) {
#ifndef NDEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    sp_qb_ = std::shared_ptr<QueryBase>(new WordQuery(word));
    auto q = Query(sp_qb_);
    logger->AddToLogger(q);
}

Query operator&(const Query &lhs, const Query &rhs) {
    auto q = Query(std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs)));
    logger->AddToLogger(q);
    return q;
//    return Query(std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs)));
}

Query operator|(const Query &lhs, const Query &rhs) {
    auto q = Query(std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs)));
    logger->AddToLogger(q);
    return q;
//    return Query(std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs)));
}


Query operator~(const Query &rhs) {
    auto q = Query(std::shared_ptr<QueryBase>(new NotQuery(rhs)));
    logger->AddToLogger(q);
    return q;
//    return Query(std::shared_ptr<QueryBase>(new NotQuery(rhs)));
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
