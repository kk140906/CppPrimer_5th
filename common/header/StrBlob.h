//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_STRBLOB_H
#define C___PRIMER_EXERCISE_STRBLOB_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>


class StrBlobPtr;

class StrBlob {

    friend class StrBlobPtr;

    friend bool operator==(const StrBlob &lsb, const StrBlob &rsb);

    friend bool operator!=(const StrBlob &lsb, const StrBlob &rsb);

    friend bool operator<(const StrBlob &lsb, const StrBlob &rsb);

    using container = std::vector<std::string>;
    using values = std::string;
public:
    // 使用make_shared创建智能指针更为安全
    StrBlob() : sp_container(std::make_shared<container>()) {}
    // 直接初始化会创建一个空的智能指针，一旦用户忘记了初始化，在这个指针上的所有操作都是非法的
    /*
     * auto p1 = shared_ptr<vector<string>>(); // p1返回值为nullptr,p1.use_count()为0
     * auto p2 = make_shared<vector<string>>(); // p2返回值为一个智能指针指向的地址,p2.use_count()为1
     *
     */
//    StrBlob() : data(shared_ptr<vector<string>>()) {}
    explicit StrBlob(const values &str) : sp_container(std::make_shared<container>(container{str})) {}

    StrBlob(const std::initializer_list<values> &il) : sp_container(std::make_shared<container>(il)) {}

#ifdef Exercise1325

    // 拷贝构造函数,这里不能简单的拷贝sp_container的智能指针，即不能直接sp_container = obj.sp_container
    // 同时也不能简单的拷贝智能指针指向的对象，即不能直接*sp_container = *obj.sp_container
    // 由于在定义时可以采用拷贝初始化，此时只会调用拷贝构造函数，sp_container将会是一个空的智能指针
    // 如果只是把智能指针指向的对象进行了拷贝，那么在对当前对象进行解引用赋值时的行为是未定义的
    StrBlob(const StrBlob &obj) {
        sp_container = std::make_shared<container>(*obj.sp_container);
    }

    // 拷贝赋值运算符
    StrBlob &operator=(const StrBlob &obj) {
        sp_container = std::make_shared<container>(*obj.sp_container);
        return *this;
    }

#endif

    // 右值版本
    void push_back(values &&val) {
        std::cout << "push_back &&" << std::endl;
        // 注意使用std::move移动val，这是因为val虽然是右值引用，但是它是左值，会优先使用vector的拷贝版本
        sp_container->push_back(std::move(val));
    }

    bool empty() const;

    std::size_t size() const;

    // 左值版本
    void push_back(const values &val);


    values pop_back();

    values front() const {
        if (empty()) {
            throw std::out_of_range("容器为空.");
        }
        return sp_container->front();
    }

    values back() const {
        if (empty()) {
            throw std::out_of_range("容器为空.");
        }
        return sp_container->back();
    }

    StrBlobPtr begin();

    StrBlobPtr cbegin() const;

    StrBlobPtr end();

    StrBlobPtr cend() const;

    values operator[](int cur_pos);

    void print() {
        for (auto &c: *sp_container) {
            std::cout << c << std::endl;
        }
    }

    void useCount(values identify) {
        std::cout << std::move(identify) << " - 引用计数: " << sp_container.use_count() << std::endl;
    }

private:
    std::shared_ptr<container> sp_container;
};



#endif //C___PRIMER_EXERCISE_STRBLOB_H
