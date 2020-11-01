/*
 * Exercise 15.15 定义自己的Discount_quote和Bulk_quote类
 * Exercise 15.16 改变练习15.7的打折策略，使其继承自Discount_quote类
 * Exercise 15.17 尝试定义一个Discount_quote对象，看看编译器给出的错误信息是什么
 */
#include <iostream>
#include "../common/header/Quote.h"

using namespace std;

int main() {

    cout << "--------------Quote object---------------" << endl;
    Quote q("123456789", 10);
    q.debug();
    cout << endl;
    cout << "--------------Bulk_quote object---------------" << endl;
    Bulk_quote bq("123456789", 10, 50, 0.88);
    bq.debug();
    cout << endl;
    cout << "--------------Limit_quote object---------------" << endl;
    Limit_quote lq("123456789", 10, 15, 0.76);
    lq.debug();


//    Discount_quote dq;
    return 0;
}

