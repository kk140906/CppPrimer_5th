//
// Created by KK on 2020/11/2.
//

#ifndef C___PRIMER_EXERCISE_BLOB_PTR_H
#define C___PRIMER_EXERCISE_BLOB_PTR_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "blob.h"

// 保证友元一定可以与类模板链接成功的方式有三个
// 友元函数模板的定义方式1:直接类内声明并定义



// 注意由于作用域相同，函数模板的形参不能与类模板的形参一致，否则后出现的将会隐藏先出现的
// 此外，类模板也必须先前置声明，由于在blob.h中已经声明了，在这个头文件就不再重复声明
template<typename F_>
bool operator==(const BlobPtr<F_> &lhs, const BlobPtr<F_> &rhs);

template<typename T_>
class BlobPtr {
    // 友元函数模板的定义方式2:类外声明函数模板，类内声明友元，并指定类模板形参为函数模板的实参，类外定义(头文件内定义)
    // 注意使用类模板的形参T_作为函数模板的实参
    friend bool operator==<T_>(const BlobPtr &lhs, const BlobPtr &rhs);

    // 友元函数模板的定义方式3:类内声明函数模板的所有实例都是类模板所有实例的友元，类外定义(头文件内定义)
    template<typename>
    friend bool operator!=(const BlobPtr &lhs, const BlobPtr &rhs);

    // 友元函数模板的定义方式3:类内声明函数模板的所有实例都是类模板所有实例的友元，类外定义(头文件内定义)
    template<typename>
    friend bool operator<(const BlobPtr &lhs, const BlobPtr &rhs);

public:

    using ValueType = typename Blob<T_>::ValueType;
    using ContainerType = typename Blob<T_>::ContainerType;
    using pos = std::size_t;

    BlobPtr(const pos initialPos = 0) : cur_pos(initialPos) {}

    explicit BlobPtr(const Blob<T_> &strBlob, const pos initialPos = 0) : wp_container(strBlob.sp_container_),
                                                                          cur_pos(initialPos) {}

    BlobPtr &operator++() {
        check(cur_pos);
        ++cur_pos;
        return *this;
    }

    BlobPtr operator++(int inc) {
        auto cur_obj = *this;
        ++*this;
        return cur_obj;
    }

    BlobPtr &operator--() {
        --cur_pos;
        check(cur_pos);
        return *this;
    }

    BlobPtr operator--(int inc) {
        auto cur_obj = *this;
        --*this;
        return cur_obj;
    }

    ValueType &operator*() {
        auto sp_container = check(cur_pos);
        return (*sp_container)[cur_pos];
    }

    BlobPtr operator+(int inc) {
        auto tmp = *this;
        auto tmp_pos = tmp.cur_pos + inc;
        tmp.check(tmp_pos);
        tmp.cur_pos += inc;
        return tmp;
    }

    BlobPtr operator-(int inc) {
        auto tmp = *this;
        auto tmp_pos = cur_pos - inc;
        tmp.check(tmp_pos);
        tmp.cur_pos -= inc;
        return tmp;
    }

    ValueType operator[](int inc) {
        auto tmp_pos = static_cast<pos>(inc);
        check(tmp_pos);
        cur_pos = tmp_pos;
        return **this;
    }

    ValueType *operator->() {
        return &this->wp_container.lock()->at(cur_pos);
    }

private:
    pos cur_pos;
    std::weak_ptr<ContainerType> wp_container;

    std::shared_ptr<ContainerType> check(pos &position) const {
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
};


template<typename F_>
inline bool operator==(const BlobPtr<F_> &lhs, const BlobPtr<F_> &rhs) {
    auto pDataLeft = lhs.wp_container.lock();
    auto pDataRight = rhs.wp_container.lock();
    // 两个shared_ptr指向同一区域，且保证shared_ptr对象存在的情况下才比较位置是否相等
    if (pDataLeft == pDataRight && pDataLeft) {
        return lhs.cur_pos == rhs.cur_pos;
    }
    return false;
}

template<typename T_>
inline bool operator!=(const BlobPtr<T_> &lhs, const BlobPtr<T_> &rhs) {
    return !(lhs == rhs);
}

template<typename T_>
inline bool operator<(const BlobPtr<T_> &lhs, const BlobPtr<T_> &rhs) {
    auto lsb_sp = lhs.wp_container.lock();
    auto rsb_sp = rhs.wp_container.lock();
    if (lsb_sp != rsb_sp) {
        throw std::out_of_range("BlobPtr指向的不是同一对象,无法比较.");
    }
    return lhs.cur_pos < rhs.cur_pos;
}

template<typename T_>
BlobPtr<T_> Blob<T_>::begin() {
    return BlobPtr<T_>(*this);
}

template<typename T_>
const BlobPtr<T_> Blob<T_>::cbegin() const {
    return BlobPtr<T_>(*this);
}

template<typename T_>
BlobPtr<T_> Blob<T_>::end() {
    return BlobPtr<T_>(*this, this->size());
}

template<typename T_>
const BlobPtr<T_> Blob<T_>::cend() const {
    return BlobPtr<T_>(*this, this->size());
}

template<typename T_>
typename Blob<T_>::ValueType Blob<T_>::operator[](int cur_pos) {
    return *BlobPtr<T_>(*this, cur_pos);
}

#endif //C___PRIMER_EXERCISE_BLOB_PTR_H
