/*
 * Exercise 14.43 使用标准库函数对象判断一个给定的int值是否被int容器中的所有元素整除
 */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main() {
    vector<int> vi{2, 4, 24, 1656, 18};
    modulus<int> mi;
    cout << all_of(vi.begin(), vi.end(), [&](const auto &ci) { return mi(ci, 2) == 0; }) << endl;
    cout << none_of(vi.begin(), vi.end(), std::bind(modulus<int>(), _1, 2)) << endl;

    return 0;
}

