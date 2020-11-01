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
