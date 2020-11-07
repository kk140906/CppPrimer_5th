//
// Created by KK on 2020/11/5.
//

#ifndef C___PRIMER_EXERCISE_UNIQUE_PTR_H
#define C___PRIMER_EXERCISE_UNIQUE_PTR_H

#include <iostream>
#include <functional>

template<typename T_, typename F_ = std::function<void(T_ *)>>
class UniquePtr {
public:
    using IteratorType = T_ *;
    using FunctionType = F_;

    UniquePtr(IteratorType it) : up_(it), func_([](IteratorType p) { delete p; }) {}

    UniquePtr(IteratorType it, FunctionType &&func) : up_(it), func_(std::move(func)) {}

    UniquePtr(const UniquePtr &) = delete;

    UniquePtr &operator=(const UniquePtr &) = delete;

    ~UniquePtr() { func_(up_); }

    T_ &operator*() {
        if (!up_) {
            throw std::runtime_error("Can't dereference nullptr");
        }
        return *up_;
    }

    IteratorType release() {
        IteratorType tmp = up_;
        up_ = nullptr;
        return tmp;
    }

    void reset(IteratorType q = nullptr) {
        delete up_;
        q ? up_ = q : up_ = nullptr;
    }

private:
    IteratorType up_;
    FunctionType func_;

    void Delete(IteratorType p) {
        delete p;
    }
};

#endif //C___PRIMER_EXERCISE_UNIQUE_PTR_H
