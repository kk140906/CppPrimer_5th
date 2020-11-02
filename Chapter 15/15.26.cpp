/**
 * Exercise 15.26 定义Quote类及其继承体系中的拷贝控制成员，令其功能与合成的版本行为一致，同时添加打印状态的语句，观察程序输出状态
 * Exercise 15.27 重新定义Bulk_quote，令其继承构造函数
 */

#define Exercise1527

#include <iostream>
#include "../common/header/Quote.h"

using namespace std;

int main() {

    cout << "--------------Quote object---------------" << endl;
    Quote q("123456789", 10);
    cout << endl;
    cout << "--------------Bulk_quote object---------------" << endl;
    Bulk_quote bq("123456789", 10, 50, 0.88);
    cout << endl;
    cout << "--------------Limit_quote object---------------" << endl;
    Limit_quote lq("123456789", 10, 15, 0.76);
    cout << endl;
    cout << "--------------Bulk_quote copy construct object---------------" << endl;
    Bulk_quote bq2 = bq;
    cout << endl;
    cout << "--------------Quote copy construct object---------------" << endl;
    Quote q2 = bq;
    cout << endl;
    cout << "--------------Quote copy assign object---------------" << endl;
    q2 = lq;
    cout << endl;
    cout << "--------------Quote move assign object---------------" << endl;
    q2 = std::move(lq);
    cout << endl;
    cout << "---------------Done--------------" << endl;
    cout << endl;

    return 0;
}

