/**
 * Exercise 6.44 使用内联函数比较两个string对象的长度
 */
#include <iostream>
#include <string>
#include "6.44.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    const string str1 = "hello";
    const string str2 = "world";
    cout << isShorter(str1, str2) << endl;
    return 0;
}

