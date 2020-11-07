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
    using SizeType = string::size_type;
    using pos = string::size_type;

    Screen() = default;

    Screen(const SizeType &height, const SizeType &width)
            : height(height), width(width), contents(height * width, ' ') {}

    // 初始化成员变量也是一次成员对象初始化过程.例如contents，可以传递不同的参数使contents对象调用string的不同的构造函数。
    Screen(const SizeType &height, const SizeType &width, const char &placeHolder)
            : height(height), width(width), contents(height * width, placeHolder) {}

    Screen &move(const pos col, const pos row) {
        if (col > width) throw std::out_of_range("设置的列参数超过范围");
        if (row > height) throw std::out_of_range("设置的行参数超过范围");
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

    std::pair<SizeType, SizeType> getScreenSize() const;

private:
    string contents;
    SizeType cursor;
    SizeType height, width;

    void do_display(ostream &os) const {
        for (auto h = 0; h < height; ++h) {
            for (auto w = 0; w < width; ++w) { os << contents[w + h * width]; }
            os << std::endl;
        }
    }
};

std::pair<Screen::SizeType, Screen::SizeType> Screen::getScreenSize() const {
    return {height, width};
}

// clear函数的定义，必须在Screen类定义完成之后才能定义,因为函数定义的形参类型是Screen
void WindowManager::clear(Screen &screen) {
    auto size = screen.height * screen.width;
    screen.contents = string(size, ' ');
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    const Screen cMyScreen(2, 3, '$');
    Screen myScreen(5, 200, ' ');
    myScreen.move(10, 2).set('G').display(cout);
    cout << endl;
    cMyScreen.display(cout);
    cout << endl;
    cout << "即将执行清屏操作！" << endl;
    WindowManager windowManager;
    windowManager.clear(myScreen);
    myScreen.display(cout);
    cout << endl << "清屏完成" << endl;
    cout << "当前屏幕大小为: " << myScreen.getScreenSize().first << " x " << myScreen.getScreenSize().second << endl;
    return 0;
}

