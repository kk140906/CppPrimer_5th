/*
 * Exercise 14.23 为你的StrVec类定义一个接受initializer_list的赋值运算符
 */
#include <iostream>
#include <string>
#include "../common/header/StrVec.h"

using namespace std;

int main() {

    StrVec sv1;
    sv1 = {"hello", "world"};
    for (const auto &csv : sv1) {
        cout << csv << " ";
    }

    return 0;
}

