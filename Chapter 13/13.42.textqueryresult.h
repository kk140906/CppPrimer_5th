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
#include "13.42.textquery.h"

namespace Exercise1342 {

    class TextQueryResult {
        using line_num = std::size_t;
        // 使用StrVec替换vecotr<string>
        using line_values = StrVec;
        using query_values = std::pair<std::string, std::set<line_num>>;
        using query_values_iter = std::set<line_num>::iterator;

    public:
        TextQueryResult(std::shared_ptr<line_values> &p_lineValues,
                        std::shared_ptr<query_values> &p_queryValues,
                        std::ostream &o_stream)
                : wp_lineValues(p_lineValues), wp_queryValues(p_queryValues), os(o_stream) {}

        void print();

        query_values_iter begin();

        query_values_iter end();

        std::shared_ptr<line_values> get_file();

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

    inline std::shared_ptr<TextQueryResult::line_values> TextQueryResult::get_file() {
        return wp_lineValues.lock();
    }

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
}

#endif //C___PRIMER_EXERCISE_12_32_TEXTQUERYRESULT_H
