/**
 * @details : Exercise 16.51 调用本节中的每个foo，确定sizeof...(Args)和sizeof...(rest)分别返回什么
 * @details : Exercise 16.52 编写一个程序验证16.51的答案
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>


using namespace std;

template<typename T1_, typename ... Args>
void foo(const T1_ &t, const Args &...rest) {
    cout << sizeof...(Args) << " " << sizeof...(rest) << endl;
}

int main() {

    int i = 0;
    double d = 3.14;
    string s("hello");
    foo(i, s, 42, d);
    foo(i, d);
    foo(i, 42);
    foo("hi");
    return 0;
}

