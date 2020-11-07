/**
 * @details : Exercise 16.47 编写自己版本的翻转函数，通过接受左值和右值引用参数的函数来测试它
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>

using namespace std;

template<typename F_, typename T1_, typename T2_>
void Flip(F_ func, T1_ &&arg1, T2_ &&arg2) {
    func(std::forward<T1_>(arg1), std::forward<T2_>(arg2));
}

void print(int i, int &&j) {
    cout << i << " " << j << endl;
}

int main() {

    int i = 42;
    Flip(print, i, 5);
    Flip(print, 5, 5);
    return 0;
}

