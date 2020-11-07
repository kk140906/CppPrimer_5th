//
// Created by KK on 2020/11/4.
//

#ifndef C___PRIMER_EXERCISE_VEC_H
#define C___PRIMER_EXERCISE_VEC_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <algorithm>

template<typename T_>
class Vec {
    friend bool operator==(const Vec &lsv, const Vec &rsv) {
        if (lsv.size() != rsv.size()) {
            return false;
        }
        auto lsv_begin = lsv.cbegin();
        auto rsv_begin = rsv.cbegin();
        while (lsv_begin != lsv.cend()) {
            if (*lsv_begin++ != *rsv_begin++) { return false; }
        }
        return true;
    }

    friend bool operator!=(const Vec &lsv, const Vec &rsv) {
        return !(lsv == rsv);
    }

    // 比较StrVec中每个元素
    friend bool operator<(const Vec &lsv, const Vec &rsv) {
        return std::lexicographical_compare(lsv.elements, lsv.first_free, rsv.elements, rsv.first_free);
    }

    using IteratorType = T_ *;
    using ConstIteratorType = const T_ *;
    using IteratorPairType = std::pair<IteratorType, IteratorType>;
    using ValueType = T_;
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) { std::cout << "调用默认构造函数" << std::endl; }

    Vec(std::initializer_list<ValueType> il) {
        std::cout << "调用方括号初始化列表构造函数" << std::endl;
        auto new_iter_pair = alloc_n_copy(il.begin(), il.end());
        elements = new_iter_pair.first;
        first_free = cap = new_iter_pair.second;
    }

    Vec(const Vec &rsv) {
        std::cout << "调用拷贝构造函数" << std::endl;
        auto new_iter_pair = alloc_n_copy(rsv.cbegin(), rsv.cend());
        elements = new_iter_pair.first;
        first_free = cap = new_iter_pair.second;
    }

    Vec(Vec &&rsv) noexcept {
        std::cout << "调用移动构造函数" << std::endl;
        move_iter(rsv.elements, rsv.first_free, rsv.cap);
    }

    Vec &operator=(const Vec &rsv) {
        std::cout << "调用拷贝赋值运算符" << std::endl;
        auto new_iter_pair = alloc_n_copy(rsv.cbegin(), rsv.cend());
        // 注意free一定要在copy之后，否则在自赋值时会清空所有内容；
        free();
        elements = new_iter_pair.first;
        first_free = cap = new_iter_pair.second;
        return *this;
    }

    Vec &operator=(const std::initializer_list<std::string> &il) {
        std::cout << "调用重载的接受initializer_list的赋值运算符" << std::endl;
        auto new_iter_pair = alloc_n_copy(il.begin(), il.end());
        elements = new_iter_pair.first;
        first_free = cap = new_iter_pair.second;
        return *this;
    }

    Vec &operator=(Vec &&rsv) noexcept {
        std::cout << "调用移动赋值运算符" << std::endl;
        if (this != &rsv) {
            free();
            move_iter(rsv.elements, rsv.first_free, rsv.cap);
        }
        return *this;
    }

    ValueType &operator[](std::size_t pos) {
        if (pos > size() - 1) { throw std::range_error("Subscript over range."); }
        return *(elements + pos);
    }

    ~Vec() { free(); }

    bool empty() const { return first_free == elements; }

    std::size_t size() const { return first_free - elements; }

    std::size_t capacity() const { return cap - elements; }

    void push_back(const ValueType &str) {
        chk_n_alloc();
        alloc.construct(first_free++, str);
    }

    // 部分类型,如string具有多个多个构造函数，参数各不向相同，需要使用参数包
    template<typename ... Args>
    void emplace_back(Args &&...args) {
        chk_n_alloc();
        // 转发参数包到构造器，同时扩展模板参数包及函数参数包
        alloc.construct(first_free++, std::forward<Args>(args)...);
    }

    ConstIteratorType cbegin() const { return elements; }

    ConstIteratorType cend() const { return first_free; }

    IteratorType begin() { return elements; }

    IteratorType end() { return first_free; }

    void reserve(std::size_t n) {
        if (n > capacity()) {
            auto new_iter_pair = alloc_n_copy(begin(), end());
            free();
            elements = new_iter_pair.first;
            first_free = new_iter_pair.second;
            cap = elements + n;
        }

    }

    void resize(std::size_t n, const ValueType &str = "") {
        while (n > size()) {
            push_back(str);
        }

        while (n < size()) {
            alloc.destroy(--first_free);
            // 注意capacity跟着size一起改变，如果不一起改变，那么多次resize之后，capacity将会变得混乱
            --cap;
        }

    }


private:
    IteratorType elements;
    IteratorType first_free;
    IteratorType cap;
    static std::allocator<ValueType> alloc;

    bool full() const { return first_free != elements && first_free == cap; }

    // 检查是否有空间存放新的元素，没有则重新分配内存
    void chk_n_alloc() {
        // 根据容器是否已满或者为空进行内存的重新分配，另一个方式是比较size()与capacity()是否相等
        // 利用第二个方式相对较好，当两者相同时，就暗含了容器是否为空或者已满，这样不容易漏掉别的条件
        if (full() || empty()) {
            reallocate();
        }
    }

    // 拷贝一个给定范围中的元素到新的空间中
    static IteratorPairType alloc_n_copy(ConstIteratorType b, ConstIteratorType e) {
        auto size = e - b;
        auto new_elements = alloc.allocate(size);
        // 由于allocator分配的内存是未初始化的，只能调用uninitialized_copy，通过构造对象进行拷贝
        auto new_first_free = std::uninitialized_copy(b, e, new_elements);
        return {new_elements, new_first_free};
    }

    void reallocate() {
        // 计算需要重新分配的大小
        auto new_capacity = size() ? size() * 2 : 1;
        auto new_elements = alloc.allocate(new_capacity);
        auto dest_elements = new_elements;
        // 使用move移动对象，减少拷贝
        // for_each算法对迭代器进行了解引用操作，lambda接收的参数应该是解引用以后的对象,即string对象
        std::for_each(elements, first_free,
                      [&](auto &s)mutable {
                          alloc.construct(dest_elements++, std::move(s));
                      });
        free();
        // 当源StrVec中为null时，并未进行移动；new_elements = dest_elements
        // 当源StrVec不为null时，进行移动；new_elements = dest_elements - capacity();
        elements = new_elements;
        first_free = dest_elements;
        cap = elements + new_capacity;
    }

    void move_iter(IteratorType &b, IteratorType &e, IteratorType &c) {
        elements = b;
        first_free = e;
        cap = c;
        b = e = c = nullptr;
    }

    void free() const {
        if (elements) {
            // lambda形式的free
            std::for_each(elements, first_free, [](auto &v) { alloc.destroy(&v); });
//        while (first_free != elements) {
//            alloc.destroy(--first_free);
//        }
            alloc.deallocate(elements, capacity());
        }
    }
};

// 静态成员必须在类外进行定义，否则会报undefined alloc的错误
template<typename T_>
std::allocator<typename Vec<T_>::ValueType> Vec<T_>::alloc;
#endif //C___PRIMER_EXERCISE_VEC_H
