//
// Created by KK on 2020/10/31.
//

#include "../header/text_query.h"

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

TextQuery::ResultTupleType TextQuery::query_return_tuple(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    auto iter_found = wordDicts.find(word);
    if (iter_found != wordDicts.end()) {
        p_queryValues = std::make_shared<query_values>(query_values(word, wordDicts[word]));
    } else {
        p_queryValues = std::make_shared<query_values>(query_values(word, std::set<line_num>()));
    }
    return ResultTupleType(p_lineValues, p_queryValues);
}
