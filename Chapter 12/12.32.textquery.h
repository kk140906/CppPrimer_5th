//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_12_32_TEXTQUERY_H
#define C___PRIMER_EXERCISE_12_32_TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <memory>
#include "12.32.StrBlob.h"
#include "12.32.StrBlobPtr.h"

namespace Exercise1232 {

    class TextQueryResult;

    class TextQuery {
        using line_num = std::size_t;
        // StrBlob和StrBlobPtr仿照标准库编写，更改using别名即可的类型即可实现替换功能
        using line_values = StrBlob;
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
}


#endif //C___PRIMER_EXERCISE_12_32_TEXTQUERY_H
