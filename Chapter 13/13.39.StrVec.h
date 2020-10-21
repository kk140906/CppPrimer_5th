//
// Created by KK on 2020/10/17.
//

#ifndef C___PRIMER_EXERCISE_STRVEC_H
#define C___PRIMER_EXERCISE_STRVEC_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

class StrVec {
    using iter = std::string *;
    using iter_pair = std::pair<StrVec::iter, StrVec::iter>;
    using content = std::string;
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { std::cout << "调用默认构造函数" << std::endl; }

    StrVec(std::initializer_list<content> il) {
        // alloc_n_copy接受的参数是引用类型，而initializer_list返回的的迭代器类型是constexpr,需要进行类型转换
        std::cout << "调用方括号初始化列表构造函数" << std::endl;
        auto new_iter_pair = alloc_n_copy(const_cast<iter>(il.begin()), const_cast<iter>(il.end()));
        elements = new_iter_pair.first;
        first_free = cap = new_iter_pair.second;
    }

    StrVec(const StrVec &);

    StrVec(StrVec &&) noexcept;

    StrVec &operator=(const StrVec &);

    StrVec &operator=(StrVec &&) noexcept;

    ~StrVec() { free(); }

    bool empty() const;

    std::size_t size() const;

    std::size_t capacity() const;

    void push_back(const content &str);

    iter begin();

    iter end();

    iter cbegin() const;

    iter cend() const;

    void reserve(std::size_t n);

    void resize(std::size_t n, const content &str = "");

    content operator[](std::size_t pos);

private:
    iter elements;
    iter first_free;
    iter cap;
    static std::allocator<content> alloc;

    bool full() const;

    // 检查是否有空间存放新的元素，没有则重新分配内存
    void chk_n_alloc();

    // 拷贝一个给定范围中的元素到新的空间中
    static iter_pair alloc_n_copy(const iter &b, const iter &e);

    void reallocate();

    void move_iter(iter &b, iter &e, iter &c);

    void free();
};


#endif //C___PRIMER_EXERCISE_STRVEC_H
