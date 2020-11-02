/**
 * Exercise 15.5 定义自己的Bulk_quote类
 * Exercise 15.6 将Quote和Bulk_quote对象传递给print_total函数，验证程序的正确性
 */
#include <iostream>
#include "../common/header/Quote.h"

using namespace std;

int main() {

    cout << "--------------Quote object---------------" << endl;
    Quote q("123456789", 66.9);
    print_totals(cout, q, 70);
    cout << endl;
    cout << "--------------Bulk_quote object---------------" << endl;
    Bulk_quote bq("123456789", 66.9, 50, 0.5);
    print_totals(cout, bq, 70);
    return 0;
}

