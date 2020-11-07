//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_STRBLOBPTR_H
#define C___PRIMER_EXERCISE_STRBLOBPTR_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "StrBlob.h"


using contianer = std::vector<std::string>;
using pos = std::size_t;

class StrBlobPtr {

    friend bool operator==(const StrBlobPtr &lsbp, const StrBlobPtr &rsbp);

    friend bool operator!=(const StrBlobPtr &lsbp, const StrBlobPtr &rsbp);

    friend bool operator<(const StrBlobPtr &lsbp, const StrBlobPtr &rsbp);

public:
    StrBlobPtr(const pos initialPos = 0) : cur_pos(initialPos) {}

    explicit StrBlobPtr(const StrBlob &strBlob, const pos initialPos = 0) : wp_container(strBlob.sp_container),
                                                                            cur_pos(initialPos) {}

    StrBlobPtr &operator++();

    StrBlobPtr operator++(int inc);

    StrBlobPtr &operator--();

    StrBlobPtr operator--(int inc);

    std::string &operator*();

    StrBlobPtr operator+(int inc);

    StrBlobPtr operator-(int inc);

    std::string operator[](int inc);

    const std::string *operator->() const;

private:
    pos cur_pos;
    std::weak_ptr<contianer> wp_container;

    std::shared_ptr<contianer> check(pos &position) const;
};



#endif //C___PRIMER_EXERCISE_STRBLOBPTR_H


