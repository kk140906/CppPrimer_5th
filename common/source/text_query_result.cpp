//
// Created by KK on 2020/10/31.
//
#include "../header/text_query_result.h"

void TextQueryResult::print() {
    os << p_queryValues_->first << " occurs " << p_queryValues_->second.size() << " times" << std::endl;
    for (const auto &cv : p_queryValues_->second) {
        os << "(line " << cv + 1 << ") " << (*p_lineValues_)[cv] << std::endl;
    }
}


TextQueryResult::query_values_iter TextQueryResult::begin() const {

    return p_queryValues_->second.begin();
}

TextQueryResult::query_values_iter TextQueryResult::end() const {
    return p_queryValues_->second.end();
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
