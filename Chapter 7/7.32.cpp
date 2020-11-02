/**
 * Exercise 7.32 给Screen添加一个友元函数，该函数是WindowManager的成员函数，可以clear Screen的显示内容
 * */
#include <iostream>
#include <string>

using namespace std;

// Screen类的前向声明，以保证WindowManager类在定义时能够完成对Screen对象的声明；
class Screen;

// 仅声明clear函数，不能定义，而且必须是公有成员函数，否则在Screen类中声明为其友元函数时会出现错误
class WindowManager {
public:
    void clear(Screen &screen);
};

class Screen {
    // 声明clear函数为Screen类的友元函数
    friend void WindowManager::clear(Screen &screen);

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

    screen_size getScreenSize() const;

private:
    string contents;
    screen_size cursor;
    screen_size height, width;

    void do_display(ostream &os) const { os << contents; }
};

Screen::screen_size Screen::getScreenSize() const {
    return height * width;
}

// clear函数的定义，必须在Screen类定义完成之后才能定义,因为函数定义的形参类型是Screen
void WindowManager::clear(Screen &screen) {
    auto size = screen.height * screen.width;
    screen.contents = string(size, ' ');
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    const Screen cMyScreen(60, 30, '$');
    Screen myScreen(50, 32, ' ');
    myScreen.move(10, 0).set('G').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
    cMyScreen.display(cout);
    cout << endl;
    cout << "即将执行清屏操作！" << endl;
    WindowManager windowManager;
    windowManager.clear(myScreen);
    myScreen.display(cout);
    cout << endl << "清屏完成" << endl;
    cout << "当前屏幕大小为:" << myScreen.getScreenSize() << endl;
    return 0;
}

