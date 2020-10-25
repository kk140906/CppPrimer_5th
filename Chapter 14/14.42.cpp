/*
 * Exercise 14.42 使用标准库函数对象及适配器定义一条表达式，令其
 * (a)统计大于1024的值有多少个
 * (b)找到第一个不等于pooh的字符串
 * (c)将所有值乘以2
 */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main() {
    vector<int> vi{1, 234, 345, 134134, 134, 2341234, 132412, 123, 4654, 6, 92380};

    cout << count_if(vi.begin(), vi.end(), std::bind(greater<int>(), _1, 1024)) << endl;

    vector<string> vs{"pooh", "hello", "word"};
    cout << *find_if(vs.begin(), vs.end(), std::bind(not_equal_to<string>(), _1, "pooh")) << endl;

    transform(vi.begin(), vi.end(), vi.begin(), std::bind(multiplies<int>(), _1, 2));
    for (const auto &ci : vi) {
        cout << ci << " ";
    }

    return 0;
}

