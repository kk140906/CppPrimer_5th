/*
 * Exercise 15.11 为你的Quote体系添加一个名为debug的函数，令其分别显示每个类的数据成员
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

    return 0;
}

