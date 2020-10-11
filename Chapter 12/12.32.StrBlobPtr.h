//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_12_32_STRBLOBPTR_H
#define C___PRIMER_EXERCISE_12_32_STRBLOBPTR_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "12.32.StrBlob.h"

namespace Exercise1232 {

    using continer = std::vector<std::string>;
    using pos = std::size_t;

    class StrBlobPtr {

    public:
        StrBlobPtr(const pos initialPos = 0) : cur_pos(initialPos) {}

        explicit StrBlobPtr(const StrBlob &strBlob, const pos initialPos = 0) : wp_container(strBlob.sp_container),
                                                                                cur_pos(initialPos) {}

        StrBlobPtr &operator++();

        StrBlobPtr operator++(int inc);

        StrBlobPtr &operator--();

        StrBlobPtr operator--(int inc);

        std::string operator*();

        StrBlobPtr operator+(int inc);

        StrBlobPtr operator-(int inc);

        std::string operator[](int inc);

        bool operator==(const StrBlobPtr &right) const;

        bool operator!=(const StrBlobPtr &right) const;

    private:
        pos cur_pos;
        std::weak_ptr<continer> wp_container;

        std::shared_ptr<continer> check(pos &position) const;
    };

    // 前置++返回对下个对象的引用
    inline StrBlobPtr &StrBlobPtr::operator++() {
        check(cur_pos);
        ++cur_pos;
        return *this;
    }

    // 后置++返回当前对象的副本,后置版本没必要检查位置是否正确,调用前置版本的++会进行检查
    inline StrBlobPtr StrBlobPtr::operator++(int inc) {
        auto cur_obj = *this;
        ++*this;
        return cur_obj;
    }

    // 前置--返回对下个对象的引用
    inline StrBlobPtr &StrBlobPtr::operator--() {
        --cur_pos;
        check(cur_pos);
        return *this;

    }

    // 后置--返回当前对象的副本,后置版本没必要检查位置是否正确,调用前置版本的--会进行检查
    inline StrBlobPtr StrBlobPtr::operator--(int inc) {
        auto cur_obj = *this;
        --*this;
        return cur_obj;
    }

    inline std::string StrBlobPtr::operator*() {
        auto sp_container = check(cur_pos);
        return (*sp_container)[cur_pos];
    }

    inline bool StrBlobPtr::operator==(const StrBlobPtr &right) const {

        auto pDataLeft = this->wp_container.lock();
        auto pDataRight = right.wp_container.lock();
        // 两个shared_ptr指向同一区域，且保证shared_ptr对象存在的情况下才比较位置是否相等
        if (pDataLeft == pDataRight && pDataLeft) {
            return this->cur_pos == right.cur_pos;
        }
        return false;

    }

    inline bool StrBlobPtr::operator!=(const StrBlobPtr &right) const {
        return !(*this == right);
    }

    inline StrBlobPtr StrBlobPtr::operator+(int inc) {
        auto tmp_pos = cur_pos + inc;
        check(tmp_pos);
        cur_pos += inc;
        return *this;
    }

    inline StrBlobPtr StrBlobPtr::operator-(int inc) {
        auto tmp_pos = cur_pos - inc;
        check(tmp_pos);
        cur_pos -= inc;
        return *this;
    }

    inline std::shared_ptr<continer> StrBlobPtr::check(pos &position) const {

        auto ret = wp_container.lock();
        if (!ret) {
            throw std::runtime_error("Bounded StrBlob Object is deleted");
        } else if (position >= ret->size()) {
            throw std::out_of_range("StrBlob Object index more than the last index");
        } else if (position < 0) {
            throw std::out_of_range("StrBlob Object index less than the first index");
        }
        return ret;
    }

    inline std::string StrBlobPtr::operator[](int inc) {
        auto tmp_pos = static_cast<pos>(inc);
        check(tmp_pos);
        cur_pos = tmp_pos;
        return **this;
    }


    inline StrBlobPtr StrBlob::begin() {
        return StrBlobPtr(*this);
    }

    inline StrBlobPtr StrBlob::cbegin() const {
        return StrBlobPtr(*this);
    }

    inline StrBlobPtr StrBlob::end() {
        return StrBlobPtr(*this, this->size());
    }

    inline StrBlobPtr StrBlob::cend() const {
        return StrBlobPtr(*this, this->size());
    }

    inline StrBlob::values StrBlob::operator[](int cur_pos) {

        return *StrBlobPtr(*this, cur_pos);
    }
}
#endif //C___PRIMER_EXERCISE_12_32_STRBLOBPTR_H


