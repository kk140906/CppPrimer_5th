/**
 * Exercise 7.23-7.24  编写自己的screen类
 * 添加三个构造函数：一个默认构造函数，一个可以接受宽和高的值，然后将contents初始化成给定数量的空白；
 * 第三个接受宽和高，以及一个字符，该字符作为初始化之后的屏幕内容
 * */
#include <iostream>
#include <string>

using namespace std;

class Screen {
public:
    using SizeType = string::size_type;

    Screen() = default;

    Screen(const SizeType &height, const SizeType &width)
            : height(height), width(width), contents(height * width, ' ') {}

    // 初始化成员变量也是一次成员对象初始化过程.例如contents，可以传递不同的参数使contents对象调用string的不同的构造函数。
    Screen(const SizeType &height, const SizeType &width, const char &placeHolder)
            : height(height), width(width), contents(height * width, placeHolder) {}

private:
    string contents;
    SizeType cursor;
    SizeType height, width;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Screen(60, 30);
    Screen(50, 32, 'H');
    return 0;
}

