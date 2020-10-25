//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_TEXTQUERY_H
#define C___PRIMER_EXERCISE_TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <memory>

// TODO: 头文件引入顺序问题分析
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "StrVec.h"


class TextQueryResult;

class TextQuery {
    using line_num = std::size_t;

#if defined(Exercise1227) || defined(Exercise1230)
    using line_values = std::vector<std::string>;
#elif  defined(Exercise1232) || defined(Exercise1233)
    using line_values = StrBlob;
#elif defined(Exercise1342)
    // StrVec替换vector<string>
    using line_values = StrVec;
#endif
    using word_dicts = std::unordered_map<std::string, std::set<line_num>>;
    using query_values = std::pair<std::string, std::set<line_num>>;

public:
    TextQuery() = default;

    TextQuery(const std::string &file) :
            p_lineValues(std::make_shared<line_values>()),
            p_queryValues(std::make_shared<query_values>()) {
        read(file);
        toDicts();
    }

    TextQueryResult query(std::string word);

private:

    std::shared_ptr<line_values> p_lineValues;
    std::shared_ptr<query_values> p_queryValues;
    word_dicts wordDicts;

    void read(const std::string &file);

    void toDicts();

};

void TextQuery::read(const std::string &file) {
    std::ifstream in_file(file);
    if (!in_file) {
        std::cout << file << " - open fail." << std::endl;
        exit(-1);
    }
    std::string value;
    while (std::getline(in_file, value)) {
        p_lineValues->push_back(value);
    }
}

void TextQuery::toDicts() {
    line_num count = 0;
    for (const auto &cl : *p_lineValues) {
        std::istringstream istream_line(cl);
        std::string word;
        while (istream_line >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            wordDicts[word].insert(count);
        }
        ++count;
    }
}


#endif //C___PRIMER_EXERCISE_TEXTQUERY_H
