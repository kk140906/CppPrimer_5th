/**
 * @details : Exercise 16.14 编写Screen类模板，用非类型参数定义宽和高
 * @details : Exercise 16.15 为Screen类编写输入输出运算符
 */
#include <iostream>
#include <string>
#include <algorithm>

#include "../common/header/screen.h"


using namespace std;

int main() {

    std::cout << "Hello, World!" << std::endl;
    const Screen<5, 6> cMyScreen('$');
    Screen<3, 4> myScreen;
    myScreen.move(3, 1).set('G').display(cout);
    cout << endl;
    cMyScreen.display(cout);
    cout << endl;
    cout << "即将执行清屏操作！" << endl;
    myScreen.clear();
    myScreen.display(cout);
    cout << endl << "清屏完成" << endl;
    cout << "当前屏幕大小为: " << myScreen.getScreenSize().first << " x " << myScreen.getScreenSize().second << endl;
    cout << "--------------------->> <<-----------------------" << endl;
    cin >> myScreen;
    cout << myScreen;
    return 0;
}

