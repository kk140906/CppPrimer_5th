/**
 * Exercise 16.2 编写并测试你自己版本的Compare函数
 * Exercise 16.3 对两个Sales_data对象调用Compare函数，观察编译器的错误
 * Exercise 16.39 使用一个显式模板实参，使得可以向函数传递两个字符串字面值
 */
#include <iostream>
#include <string>
#include <functional>
#include "../common/header/Sales_data.h"

using namespace std;

template<typename T>
int Compare(const T &lhs, const T &rhs) {
    std::less<T> less;
    if (less(lhs, rhs)) { return -1; }
    else if (less(rhs, lhs)) { return 1; }
    else { return 0; }
}


int main() {
    cout << "--------------Compare Integer-----------------" << endl;
    cout << Compare(1, 2) << endl;
    cout << "--------------Compare Float-----------------" << endl;
    cout << Compare(2.5, 2.0) << endl;
    cout << "--------------Compare Double-----------------" << endl;
    double d_1 = 1.66, d_2 = 2.4;
    cout << Compare(d_1, d_2) << endl;
    cout << "--------------Compare String-----------------" << endl;
    cout << Compare("hello", "world") << endl;
    cout << "--------------Compare Sales_data-----------------" << endl;
    Sales_data sales_data_1, sales_data_2;
//    cout << Compare(sales_data_1,sales_data_2) << endl;

    cout << "--------------Compare String by explicit -----------------" << endl;
    cout << Compare<string>("hello", "today") << endl;
    return 0;
}

