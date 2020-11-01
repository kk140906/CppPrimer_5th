/*
 * Exercise 15.7 定义一个新的类使其实现一种数量首先的折扣策略，具体策略是：
 * 当购买的书籍数量不超过一个给定的限制数量时享受折扣，如果超过限定的数量则超过部分按照原价销售
 */
#include <iostream>
#include "../common/header/Quote.h"

using namespace std;

int main() {

    cout << "--------------Bulk_quote object---------------" << endl;
    Limit_quote bq("123456789", 10, 2, 0.5);
    print_totals(cout, bq, 4);
    return 0;
}

