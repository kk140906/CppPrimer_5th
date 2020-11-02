/**
 * Exercise 14.2 为Sales_data编写重载的输入、输出、加法和复合赋值运算符；
 * Exercise 14.6 为Sales_data定义输出运算符;
 * Exercise 14.9 为Sales_data定义输入运算符;
 * Exercise 14.10 为Sales_data输入以下内容测试输出；a) 0-201-99999-9 10 24.95; b)10 24.95 0-201-99999-9;
 */
#include <iostream>
#include <string>
#include "../common/header/Sales_data.h"

using namespace std;

int main() {
    Sales_data d1("123456789", 10, 66.8), d2;
    cin >> d2;
    cout << d1 + d2;
    return 0;
}

