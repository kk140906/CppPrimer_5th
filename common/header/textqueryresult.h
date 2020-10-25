//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_12_32_TEXTQUERYRESULT_H
#define C___PRIMER_EXERCISE_12_32_TEXTQUERYRESULT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include "textquery.h"


class TextQueryResult {
    using line_num = std::size_t;

#if defined(Exercise1227) || defined(Exercise1230)
    using line_values = std::vector<std::string>;
#elif defined(Exercise1232) || defined(Exercise1233)
    // StrBlob和StrBlobPtr仿照标准库编写，更改using别名即可的类型即可实现替换功能
    using line_values = StrBlob;
#elif defined(Exercise1342)
    // 使用StrVec替换vecotr<string>
    using line_values = StrVec;
#endif
    using query_values = std::pair<std::string, std::set<line_num>>;
    using query_values_iter = std::set<line_num>::iterator;

public:
    TextQueryResult(std::shared_ptr<line_values> &p_lineValues,
                    std::shared_ptr<query_values> &p_queryValues,
                    std::ostream &o_stream)
            : wp_lineValues(p_lineValues), wp_queryValues(p_queryValues), os(o_stream) {}

    void print();

    // begin 和 end 可能在后面被经常使用，不使用条件编译进行限制
    query_values_iter begin();

    query_values_iter end();

#ifdef Exercise1233

    std::shared_ptr<line_values> get_file();

#endif
private:
    std::ostream &os;
    std::weak_ptr<line_values> wp_lineValues;
    std::weak_ptr<query_values> wp_queryValues;
};

void TextQueryResult::print() {
    auto p_lineValues = wp_lineValues.lock();
    if (!p_lineValues) {
        exit(-1);
    }
    auto p_queryValues = wp_queryValues.lock();
    if (!p_queryValues) {
        exit(-1);
    }
    os << p_queryValues->first << " occurs " << p_queryValues->second.size() << " times" << std::endl;
    for (const auto &cv : p_queryValues->second) {
        os << "(line " << cv + 1 << ") " << (*p_lineValues)[cv] << std::endl;
    }
}


inline TextQueryResult::query_values_iter TextQueryResult::begin() {
    auto p_queryValues = wp_queryValues.lock();
    if (!p_queryValues) {
        exit(-1);
    }
    return p_queryValues->second.begin();
}

inline TextQueryResult::query_values_iter TextQueryResult::end() {
    auto p_queryValues = wp_queryValues.lock();
    if (!p_queryValues) {
        exit(-1);
    }
    return p_queryValues->second.end();
}

#ifdef Exercise1233

inline std::shared_ptr<TextQueryResult::line_values> TextQueryResult::get_file() {
    return wp_lineValues.lock();
}

#endif

TextQueryResult TextQuery::query(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    auto iter_found = wordDicts.find(word);
    if (iter_found != wordDicts.end()) {
        p_queryValues = std::make_shared<query_values>(query_values(word, wordDicts[word]));
    } else {
        p_queryValues = std::make_shared<query_values>(query_values(word, std::set<line_num>()));
    }
    return TextQueryResult(p_lineValues, p_queryValues, std::cout);
}


#endif //C___PRIMER_EXERCISE_12_32_TEXTQUERYRESULT_H
