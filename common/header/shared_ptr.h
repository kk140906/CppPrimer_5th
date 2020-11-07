//
// Created by KK on 2020/11/4.
//

#ifndef C___PRIMER_EXERCISE_SHARD_PTR_H
#define C___PRIMER_EXERCISE_SHARD_PTR_H

#include <iostream>
#include <functional>

template<typename T_>
class SharedPtr {
public:
    using IteratorType = T_ *;

    SharedPtr() : use_(new std::size_t(1)), sp_(nullptr) {};

    SharedPtr(const T_ &value) : use_(new std::size_t(1)), sp_(new T_(value)) {}

    template<typename F_>
    SharedPtr(const T_ &value, F_ function) : use_(new std::size_t(1)), sp_(new T_(value)), function_(function) {}

    SharedPtr(const SharedPtr &rhs) : sp_(rhs.sp_) {
        ++*rhs.use_;
        use_ = rhs.use_;
    }

    SharedPtr(SharedPtr &&rhs) noexcept: sp_(std::move(rhs.sp_)) {
        ++*rhs.use_;
        use_ = std::move(rhs.use_);
    }

    ~SharedPtr() { if (--*use_ == 0) { Delete(sp_); }}

    SharedPtr &operator=(const SharedPtr &rhs) {
        ++*rhs.use_;
        if (--*use_ == 0) {
            Delete(sp_);
        }
        use_ = rhs.use_;
        sp_ = rhs.sp_;
    }

    SharedPtr &operator=(SharedPtr &&rhs) noexcept {
        ++*rhs.use_;
        if (--*use_ == 0) {
            Delete(sp_);
        }
        use_ = std::move(rhs.use_);
        sp_ = std::move(rhs.sp_);
    }

    T_ &operator*() {
        if (*use_ == 0 || sp_ == nullptr) {
            throw std::runtime_error("Can't dereference nullptr");
        }
        return *sp_;
    }

    void reset(IteratorType q = nullptr) {
        if (--*use_ == 0) {
            Delete(sp_);
        }
        if (q) {
            sp_ = q;
            use_ = new std::size_t(1);
        }
    }

    template<typename F_>
    void reset(IteratorType q, F_ func) {
        function_ = func;
        reset(q);
    }

    std::size_t UseCount() const {
        if (!sp_) {
            throw std::runtime_error("SharedPtr is nullptr.");
        }
        return *use_;
    }


private:
    std::size_t *use_;
    IteratorType sp_;
    std::function<void(IteratorType)> function_ = nullptr;

    void Delete(IteratorType p) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        function_ ? function_(p) : delete p;
        delete use_;
        use_ = nullptr;
        sp_ = nullptr;
    }
};

// 通过设定两个模板形参保证make_shared第一个模板参数必须通过显式指定，第二个模板参数根据函数值进行推导
template<typename T1_, typename T2_>
SharedPtr<T1_> make_shared(T2_ &&value) {
    return SharedPtr<T1_>(std::forward<T2_>(value));
}

#endif //C___PRIMER_EXERCISE_SHARD_PTR_H
