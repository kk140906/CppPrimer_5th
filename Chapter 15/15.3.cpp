/*
 * Exercise 15.3 定义自己的Quote类和print_total函数
 */
#include <iostream>
#include "../common/header/Quote.h"

using namespace std;

int main() {
    Quote q("123456789", 66.9);
    print_totals(cout, q, 70);
    return 0;
}

