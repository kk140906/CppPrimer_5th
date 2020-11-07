//
// Created by KK on 2020/11/4.
//

#ifndef C___PRIMER_EXERCISE_SCREEN_H
#define C___PRIMER_EXERCISE_SCREEN_H

#include <iostream>
#include <string>


template<std::size_t H_, std::size_t W_>
class Screen {
    friend std::ostream &operator<<(std::ostream &os, Screen &screen) {
        os << screen.contents;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Screen &screen) {
        is >> screen.contents;
        return is;
    }

public:
    using SizeType = std::size_t;

    Screen() : contents(H_ * W_, ' ') {}

    // 初始化成员变量也是一次成员对象初始化过程.例如contents，可以传递不同的参数使contents对象调用string的不同的构造函数。
    Screen(const char &placeHolder) : contents(H_ * W_, placeHolder) {}

    Screen &move(const SizeType col, const SizeType row) {
        if (col > W_) throw std::out_of_range("设置的列参数超过范围");
        if (row > H_) throw std::out_of_range("设置的行参数超过范围");
        cursor = col - 1 + row * W_;
        return *this;
    }

    Screen &set(char c) {
        contents[cursor] = c;
        return *this;
    }

    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

    const std::pair<SizeType, SizeType> getScreenSize() const { return {H_, W_}; }

    void clear() { contents = ' '; }

private:
    std::string contents;
    SizeType cursor;

    void do_display(std::ostream &os) const {
        for (auto h = 0; h < H_; ++h) {
            for (auto w = 0; w < W_; ++w) { os << contents[w + h * W_]; }
            os << std::endl;
        }
    }
};


#endif //C___PRIMER_EXERCISE_SCREEN_H
