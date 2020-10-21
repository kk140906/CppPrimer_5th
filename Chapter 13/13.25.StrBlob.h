//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_13_25_STRBLOB_H
#define C___PRIMER_EXERCISE_13_25_STRBLOB_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>


namespace Exercise1325 {

    class StrBlobPtr;

    class StrBlob {

        friend class StrBlobPtr;

        using container = std::vector<std::string>;
        using values = std::string;
    public:
        StrBlob() : sp_container(std::make_shared<container>()) {}

        explicit StrBlob(const values &str) : sp_container(std::make_shared<container>(container{str})) {}

        StrBlob(const std::initializer_list<values> &il) : sp_container(std::make_shared<container>(il)) {}

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

        bool empty() const;

        std::size_t size() const;

        // 左值版本
        void push_back(const values &val);

        // 右值版本
        void push_back(values &&val) {
            std::cout << "push_back &&" << std::endl;
            // 注意使用std::move移动val，这是因为val虽然是右值引用，但是它是左值，会优先使用vector的拷贝版本
            sp_container->push_back(std::move(val));
        }

        values pop_back();

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

    private:
        std::shared_ptr<container> sp_container;
    };

    inline bool StrBlob::empty() const { return sp_container->empty(); }

    inline std::size_t StrBlob::size() const { return sp_container->size(); }

    inline void StrBlob::push_back(const values &val) { sp_container->push_back(val); }

    inline StrBlob::values StrBlob::pop_back() {
        if (!empty()) {
            values str = sp_container->back();
            sp_container->pop_back();
            return str;
        } else {
            return values();
        }
    }


}
#endif //C___PRIMER_EXERCISE_13_25_STRBLOB_H
