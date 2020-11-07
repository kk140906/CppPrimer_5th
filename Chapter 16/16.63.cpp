/**
 * @details : Exercise 16.63 定义一个函数模板，统计一个给定值在一个vector中出现的次数
 *            测试你的函数函数，分别传递给它一个double的vector，一个int的vector以及一个string的vector
 * @details : Exercise 16.64 为16.43创建一个特例化版本处理vector<const char *>
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T_>
std::size_t count(const T_ &value, const std::vector<T_> &container) {
    return count(container.begin(), container.end(), value);
}

template<>
std::size_t count(const char *const &value, const std::vector<const char *> &container) {
    cout << __PRETTY_FUNCTION__ << endl;
    return count(container.begin(), container.end(), value);
}

int main() {
    vector<double> vd{1.2, 1.3, 1.2, 1.5, 1.2};
    vector<int> vi{1, 2, 3, 1, 2, 5, 6};
    vector<string> vs{"hello", "world", "a", "hello", "hi"};
    vector<const char *> vcp{"hello", "world", "a", "hello"};

    cout << count(1.2, vd) << endl;
    cout << count(3, vi) << endl;
    cout << count(string("hello"), vs) << endl;
    const char *cp = "hello";
    cout << count(cp, vcp) << endl;

    return 0;
}

