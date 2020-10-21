//
// Created by KK on 2020/10/18.
//

#ifndef C___PRIMER_EXERCISE_STRING_H
#define C___PRIMER_EXERCISE_STRING_H


#include <iostream>
#include <memory>
#include <algorithm>

namespace Exercise1344 {
    class Strings {
        using size_t = std::size_t;
        using iter_t = char *;
        using iter_ct = const char *;
        using iter_pair = std::pair<iter_t, iter_t>;
    public:
        // 注意此处using必须在public
        // 由于char是内置基本数据类型，不会继承自别的类或者命名空间，访问权限与实际定义有关
        // 例如using iter = std::string *;继承自std::string,其访问权限被重设为public，因此可以直接在类外通过类作用域进行使用
//        using values_t = char;
        using values_t = char;

        Strings() : p_start(nullptr), p_end(nullptr) {
            std::cout << "调用默认构造函数" << std::endl;
        };

        // c指向C风格类型的字符串
        Strings(iter_ct c) {
            std::cout << "调用接收C风格字符串指针的构造函数" << std::endl;
            copy_iter(c, c + strlen(c));
        };

        // 拷贝构造函数
        Strings(const Strings &rs);

        // 移动构造函数
        Strings(Strings &&rs) noexcept;

        // 拷贝赋值运算符
        Strings &operator=(const Strings &rs);

        // 移动赋值运算符
        Strings &operator=(Strings &&rs) noexcept;

        ~Strings() { free(); }

        size_t size() const;

        iter_t begin();

        iter_t end();

        iter_ct cbegin() const;

        iter_ct cend() const;


        iter_t p_end;
        iter_t p_start;
    private:
        static std::allocator<values_t> alloc;

        static iter_pair alloc_n_copy(iter_ct b, iter_ct e);

        static iter_pair alloc_n_move(iter_ct b, iter_ct e);

        // 用于拷贝迭代器
        void copy_iter(iter_ct b, iter_ct e);

        // 用于移动迭代器，参数类型为非常量的引用类型
        void move_iter(iter_t &b, iter_t &e);

        void free();

    };

    inline Strings::iter_t Exercise1344::Strings::begin() { return p_start; }

    inline Strings::iter_t Exercise1344::Strings::end() { return p_end; }

    inline Strings::Strings(const Strings &rs) {

        std::cout << "调用拷贝构造函数" << std::endl;
        copy_iter(rs.cbegin(), rs.cend());
    }

    inline Strings::iter_ct Strings::cbegin() const { return p_start; }

    inline Strings::iter_ct Strings::cend() const { return p_end; }

    inline Strings::Strings(Strings &&rs) noexcept {
        std::cout << "调用移动构造函数" << std::endl;
        move_iter(rs.p_start, rs.p_end);
    }


}

#endif //C___PRIMER_EXERCISE_STRING_H
