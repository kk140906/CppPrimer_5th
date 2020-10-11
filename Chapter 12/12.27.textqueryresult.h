//
// Created by KK on 2020/10/10.
//

#ifndef C___PRIMER_EXERCISE_12_27_TEXTQUERYRESULT_H
#define C___PRIMER_EXERCISE_12_27_TEXTQUERYRESULT_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "12.27.textquery.h"

namespace Exercise1227 {

    class TextQueryResult {

        using result_type = std::pair<std::string, std::vector<std::pair<std::size_t, std::string>>>;

    public:

        TextQueryResult() = default;

        explicit TextQueryResult(const std::shared_ptr<TextQuery> &s_ptr) : textQuery_ptr(s_ptr) {}

        void print() const;

        result_type get() const;

    private:
        // weak_ptr确保操作是在TextQuery对象的生存周期内
        std::weak_ptr<TextQuery> textQuery_ptr;
    };

    void TextQueryResult::print() const {
        auto textQuery = textQuery_ptr.lock();
        if (textQuery) {
            auto query = textQuery->queryResult;
            std::cout << query.first << " occurs " << query.second.size() << " times" << std::endl;
            for (const auto &cs :query.second) {
                // 内部计数从第0行开始，转换为从第一行开始计数
                std::cout << "(line " << cs + 1 << ") " << textQuery->fileLines[cs] << std::endl;
            }
        }
    }

    TextQueryResult::result_type TextQueryResult::get() const {

        auto textQuery = textQuery_ptr.lock();
        TextQueryResult::result_type result;
        if (textQuery) {
            auto query = textQuery->queryResult;
            result.first = query.first;
            for (const auto &cs :query.second) {
                // 内部计数从第0行开始，转换为从第一行开始计数
                result.second.emplace_back(std::pair<std::size_t, std::string>(cs + 1, textQuery->fileLines[cs]));
            }
        }
        return result;
    }
}

#endif //C___PRIMER_EXERCISE_12_27_TEXTQUERYRESULT_H
