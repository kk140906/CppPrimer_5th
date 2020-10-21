//
// Created by KK on 2020/10/17.
//

#include "13.39.StrVec.h"
#include <algorithm>

// 静态成员必须在类外进行定义，否则会报undefined alloc的错误
std::allocator<StrVec::content> StrVec::alloc;

bool StrVec::full() const { return first_free != elements && first_free == cap; }

bool StrVec::empty() const { return first_free == elements; }

std::size_t StrVec::size() const { return first_free - elements; }

std::size_t StrVec::capacity() const { return cap - elements; }

StrVec::iter StrVec::begin() { return elements; }

StrVec::iter StrVec::end() { return first_free; }

StrVec::iter StrVec::cbegin() const { return elements; }

StrVec::iter StrVec::cend() const { return first_free; }

void StrVec::push_back(const StrVec::content &str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

void StrVec::chk_n_alloc() {
    // 根据容器是否已满或者为空进行内存的重新分配，另一个方式是比较size()与capacity()是否相等
    // 利用第二个方式相对较好，当两者相同时，就暗含了容器是否为空或者已满，这样不容易漏掉别的条件
    if (full() || empty()) {
        reallocate();
    }
}

void StrVec::reallocate() {
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

void StrVec::free() {
    if (elements) {
        // lambda形式的free
        std::for_each(elements, first_free, [](auto &v) { alloc.destroy(&v); });
//        while (first_free != elements) {
//            alloc.destroy(--first_free);
//        }
        alloc.deallocate(elements, capacity());
    }
}

StrVec::iter_pair StrVec::alloc_n_copy(const StrVec::iter &b, const StrVec::iter &e) {
    auto size = e - b;
    auto new_elements = alloc.allocate(size);
    // 由于allocator分配的内存是未初始化的，只能调用uninitialized_copy，通过构造对象进行拷贝
    auto new_first_free = std::uninitialized_copy(b, e, new_elements);
    return iter_pair{new_elements, new_first_free};
}

StrVec::StrVec(const StrVec &rsv) {
    std::cout << "调用拷贝构造函数" << std::endl;
    auto new_iter_pair = alloc_n_copy(rsv.cbegin(), rsv.cend());
    elements = new_iter_pair.first;
    first_free = cap = new_iter_pair.second;
}

StrVec &StrVec::operator=(const StrVec &rsv) {
    std::cout << "调用拷贝赋值运算符" << std::endl;
    auto new_iter_pair = alloc_n_copy(rsv.cbegin(), rsv.cend());
    // 注意free一定要在copy之后，否则在自赋值时会清空所有内容；
    free();
    elements = new_iter_pair.first;
    first_free = cap = new_iter_pair.second;
    return *this;
}

void StrVec::resize(const std::size_t n, const content &str) {
    while (n > size()) {
        push_back(str);
    }

    while (n < size()) {
        alloc.destroy(--first_free);
        // 注意capacity跟着size一起改变，如果不一起改变，那么多次resize之后，capacity将会变得混乱
        --cap;
    }

}

void StrVec::reserve(const std::size_t n) {
    if (n > capacity()) {
        auto new_iter_pair = alloc_n_copy(cbegin(), cend());
        free();
        elements = new_iter_pair.first;
        first_free = new_iter_pair.second;
        cap = elements + n;
    }

}

StrVec::content StrVec::operator[](std::size_t pos) {
    if (pos > size() - 1) { throw std::range_error("Subscript over range."); }
    return *(elements + pos);
}


StrVec::StrVec(StrVec &&rsv) noexcept {
    std::cout << "调用移动构造函数" << std::endl;
    move_iter(rsv.elements, rsv.first_free, rsv.cap);
}

StrVec &StrVec::operator=(StrVec &&rsv) noexcept {
    std::cout << "调用移动赋值运算符" << std::endl;
    if (this != &rsv) {
        free();
        move_iter(rsv.elements, rsv.first_free, rsv.cap);
    }
    return *this;
}


void StrVec::move_iter(StrVec::iter &b, StrVec::iter &e, StrVec::iter &c) {
    elements = b;
    first_free = e;
    cap = c;
    b = e = c = nullptr;
}


