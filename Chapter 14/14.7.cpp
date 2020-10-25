/*
 * Exercise 14.7 为Strings类定义一个输出运算符
 */
#include <iostream>
#include "../common/header/String.h"

using namespace std;

int main(int argc, char **argv) {
    Strings a("hello world");
    cout << a << endl;
    return 0;
}


