/**
 * @details : Exercise 16.62 定义自己版本的hash<Sales_data>,
 *            并定义一个Sales_data对象的unordered_multiset，将多条交易记录保存找容器中，并打印其内容
 */

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/header/hash_sales_data.h"

using namespace std;


int main() {
    unordered_multiset<Sales_data> multi_sales_data;
    multi_sales_data.insert(Sales_data("123456", 20, 52.6));
    multi_sales_data.insert(Sales_data("123456", 30, 51));
    multi_sales_data.insert(Sales_data("abc", 5, 105));
    multi_sales_data.insert(Sales_data("abc", 20, 99.9));
    multi_sales_data.insert(Sales_data("123abc", 1, 999));
    for (const auto &cs : multi_sales_data) {
        cout << cs << endl;
    }

    return 0;
}

