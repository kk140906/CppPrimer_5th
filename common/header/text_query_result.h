//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_TEXT_QUERY_RESULT_H
#define C___PRIMER_EXERCISE_TEXT_QUERY_RESULT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include "text_query.h"


class TextQueryResult {
    using line_num = std::size_t;

#if defined(Exercise1232) || defined(Exercise1233)
    // StrBlob和StrBlobPtr仿照标准库编写，更改using别名即可的类型即可实现替换功能
    using line_values = StrBlob;
#elif defined(Exercise1342)
    // 使用StrVec替换vecotr<string>
    using line_values = StrVec;
#else
    using line_values = std::vector<std::string>;
#endif
    using query_values = std::pair<std::string, std::set<line_num>>;
    using query_values_iter = std::set<line_num>::iterator;

public:
    TextQueryResult(std::shared_ptr<line_values> p_lineValues,
                    std::shared_ptr<query_values> p_queryValues,
                    std::ostream &o_stream) : p_lineValues_(p_lineValues),
                                              p_queryValues_(p_queryValues),
                                              os(o_stream) {}


    void print();

    // begin 和 end 可能在后面被经常使用，不使用条件编译进行限制
    query_values_iter begin() const;

    query_values_iter end() const;

    std::shared_ptr<line_values> get_file() { return p_lineValues_; }

    std::ostream &stream() { return os; }

private:
    std::ostream &os;
    std::shared_ptr<line_values> p_lineValues_;
    std::shared_ptr<query_values> p_queryValues_;
};


#endif //C___PRIMER_EXERCISE_TEXT_QUERY_RESULT_H
