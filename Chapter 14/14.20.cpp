/**
 * Exercise 14.20 为你的Sales_data类定义加法和复合赋值运算符
 * Exercise 14.22 定义赋值运算符的一个新版本,使得我们可以把一个表示ISBN的string赋值给Sales_data对象
 */
#include <iostream>
#include <string>
#include "../common/header/Sales_data.h"

using namespace std;

int main() {

    Sales_data sd1("123456789", 10, 25);
    Sales_data sd2("123456789", 20, 10);
    cout << sd1 + sd2 << endl;
    Sales_data sd3;
    sd3 = "xxxxxxxxxxxxx";
    cout << sd3 << endl;

    return 0;
}

