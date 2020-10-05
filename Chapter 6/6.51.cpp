/*
 * Exercise 6.51 编写4个重载函数，分别验证调用的函数
 */
#include <iostream>

using namespace std;

void func();

void func(int i);

void func(int i, int j);

void func(double i, double j = 3.14);

int main() {
    std::cout << "Hello, World!" << std::endl;
    // 编译错误，无法匹配调用的函数
//    func(2.56,42);
    func(42);
    func(42, 0);
    func(2.56);
    func(2.56, 3.14);
    return 0;
}

void func() {
    cout << "No parameter" << endl;
}

void func(int i) {
    cout << "Only one int parameter" << endl;
}

void func(int i, int j) {
    cout << "Two int parameters" << endl;
}

void func(double i, double j) {
    cout << "Two double parameters" << endl;
}
