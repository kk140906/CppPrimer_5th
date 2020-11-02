/**
 * Exercise 7.27  给Screen类添加move,set,display操作
 * */
#include <iostream>
#include <string>

using namespace std;

class Screen {
public:
    using screen_size = string::size_type;
    using pos = string::size_type;

    Screen() = default;

    Screen(const screen_size &height, const screen_size &width)
            : height(height), width(width), contents(height * width, ' ') {}

    // 初始化成员变量也是一次成员对象初始化过程.例如contents，可以传递不同的参数使contents对象调用string的不同的构造函数。
    Screen(const screen_size &height, const screen_size &width, const char &placeHolder)
            : height(height), width(width), contents(height * width, placeHolder) {}

    Screen &move(const pos col, const pos row) {
        cursor = col - 1 + row * width;
        return *this;
    }

    Screen &set(char c) {
        contents[cursor] = c;
        return *this;
    }

    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    string contents;
    screen_size cursor;
    screen_size height, width;

    void do_display(ostream &os) const { os << contents; }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    const Screen cMyScreen(60, 30, '$');
    Screen myScreen(50, 32, ' ');
    myScreen.move(4, 0).set('G').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
    cMyScreen.display(cout);
    cout << endl;
    return 0;
}
