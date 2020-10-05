/*
 * Exercise 6.26 编写一个main函数，输出传递给main函数的所有参数
 */
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    std::cout << "Hello, World!" << std::endl;
    cout << "传递给main函数的所有实参为：" << endl;
    decltype(argc) cnt = 1;
    while (cnt++ < argc) {
        cout << *++argv << endl;
    }
    return 0;
}

