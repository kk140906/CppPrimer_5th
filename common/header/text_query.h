//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_TEXT_QUERY_H
#define C___PRIMER_EXERCISE_TEXT_QUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <memory>
#include <tuple>


// TODO: 头文件引入顺序问题分析
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "StrVec.h"


class TextQueryResult;

class TextQuery {
    using line_num = std::size_t;

#if defined(Exercise1232) || defined(Exercise1233)
    using line_values = StrBlob;
#elif defined(Exercise1342)
    // StrVec替换vector<string>
    using line_values = StrVec;
#else
    using line_values = std::vector<std::string>;
#endif
    using word_dicts = std::unordered_map<std::string, std::set<line_num>>;
    using query_values = std::pair<std::string, std::set<line_num>>;
    using ResultTupleType = std::tuple<std::shared_ptr<line_values>, std::shared_ptr<query_values>>;

public:
    TextQuery() = default;

#ifdef Exercise1622
#include "debug_delete.h"
    TextQuery(const std::string &file) :
            p_lineValues(new line_values,DebugDelete()),
            p_queryValues(new query_values,DebugDelete()) {
        read(file);
        toDicts();
    }
#else

    TextQuery(const std::string &file) :
            p_lineValues(std::make_shared<line_values>()),
            p_queryValues(std::make_shared<query_values>()) {
        read(file);
        toDicts();
    }

#endif

    TextQueryResult query(std::string word);

    ResultTupleType query_return_tuple(std::string word);


private:

    std::shared_ptr<line_values> p_lineValues;
    std::shared_ptr<query_values> p_queryValues;

    word_dicts wordDicts;

    void read(const std::string &file);

    void toDicts();

};


#endif //C___PRIMER_EXERCISE_TEXT_QUERY_H
