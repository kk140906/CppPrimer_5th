/**
 * @details : Exercise 16.37 标准库max函数有两个参数，你能在调用max时传递给它一个int和double吗，如果可以，如何做
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int i = 10;
    double d = 2.55;
    // max是接受一个模板参数的函数模板，直接传递不行两个不同类型的实参不能比较
//    max(i,d)
    // 显式指定模板实参为double类型，i会被转型为double，不能将double转型为int进行比较，double类型转换为int类型会损失精度
    max<double>(i, d);

    return 0;
}

