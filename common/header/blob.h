//
// Created by KK on 2020/11/2.
//

#ifndef C___PRIMER_EXERCISE_BLOB_H
#define C___PRIMER_EXERCISE_BLOB_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>


template<typename>
class BlobPtr;

template<typename T_>
class Blob {

    friend class BlobPtr<T_>;

    friend bool operator==(const Blob &lsb, const Blob &rsb) {
        // shared_ptr类定义了==，可以直接使用
        return lsb.sp_container_ == rsb.sp_container_;
    }

    friend bool operator!=(const Blob &lsb, const Blob &rsb) {
        return !(lsb == rsb);
    }

    friend bool operator<(const Blob &lsb, const Blob &rsb) {
        return std::lexicographical_compare(lsb.sp_container_->cbegin(), lsb.sp_container_->cend(),
                                            rsb.sp_container_->cbegin(), rsb.sp_container_->cend());
    }

public:

    using ValueType = T_;
    using ContainerType = std::vector<ValueType>;

    // 使用make_shared创建智能指针更为安全
    Blob() : sp_container_(std::make_shared<ContainerType>()) {}
    // 直接初始化会创建一个空的智能指针，一旦用户忘记了初始化，在这个指针上的所有操作都是非法的
    /*
     * auto p1 = shared_ptr<vector<string>>(); // p1返回值为nullptr,p1.use_count()为0
     * auto p2 = make_shared<vector<string>>(); // p2返回值为一个智能指针指向的地址,p2.use_count()为1
     *
     */
//    Blob() : data(shared_ptr<vector<string>>()) {}
    explicit Blob(const ValueType &str) : sp_container_(std::make_shared<ContainerType>(ContainerType{str})) {}

    template<typename It_>
    Blob(It_ begin, It_ end) : sp_container_(std::make_shared<ContainerType>(begin, end)) {}

    Blob(const std::initializer_list<ValueType> &il) : sp_container_(std::make_shared<ContainerType>(il)) {}

    // 拷贝构造函数,这里不能简单的拷贝sp_container的智能指针，即不能直接sp_container = obj.sp_container_
    // 同时也不能简单的拷贝智能指针指向的对象，即不能直接*sp_container_ = *obj.sp_container_
    // 由于在定义时可以采用拷贝初始化，此时只会调用拷贝构造函数，sp_container将会是一个空的智能指针
    // 如果只是把智能指针指向的对象进行了拷贝，那么在对当前对象进行解引用赋值时的行为是未定义的
    Blob(const Blob &obj) {
        sp_container_ = std::make_shared<ContainerType>(*obj.sp_container_);
    }

    // 拷贝赋值运算符
    Blob &operator=(const Blob &obj) {
        sp_container_ = std::make_shared<ContainerType>(*obj.sp_container_);
        return *this;
    }

    // 右值版本
    void push_back(ValueType &&val) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        // 注意使用std::move移动val，这是因为val虽然是右值引用，但是它是左值，会优先使用vector的拷贝版本
        sp_container_->push_back(std::move(val));
    }

    bool empty() const { return sp_container_->empty(); }

    std::size_t size() const { return sp_container_->size(); }

    // 左值版本
    void push_back(const ValueType &val) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        sp_container_->push_back(val);
    }

    ValueType pop_back() {
        if (!empty()) {
            ValueType value_ = sp_container_->back();
            sp_container_->pop_back();
            return value_;
        } else {
            return ValueType();
        }
    }

    ValueType front() const {
        if (empty()) {
            throw std::out_of_range("容器为空.");
        }
        return sp_container_->front();
    }

    ValueType back() const {
        if (empty()) {
            throw std::out_of_range("容器为空.");
        }
        return sp_container_->back();
    }

    BlobPtr<ValueType> begin();

    const BlobPtr<ValueType> cbegin() const;

    BlobPtr<ValueType> end();

    const BlobPtr<ValueType> cend() const;

    ValueType operator[](int cur_pos);

    void print() {
        for (auto &c: *sp_container_) {
            std::cout << c << std::endl;
        }
    }

    void useCount(ValueType identify) {
        std::cout << std::move(identify) << " - 引用计数: " << sp_container_.use_count() << std::endl;
    }

private:
    std::shared_ptr<ContainerType> sp_container_;
};


#endif //C___PRIMER_EXERCISE_BLOB_H
