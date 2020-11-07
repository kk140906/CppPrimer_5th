/**
 * @details : Exercise 16.41 编写新的版本的sum，保证它的返回值类型足够容纳加法计算的结果
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>

using namespace std;

template<typename T1_, typename T2_>
auto Sum(const T1_ &lhs, const T2_ &rhs) -> decltype(lhs + rhs) {
    return lhs + rhs;
}

int main() {
    cout << Sum(1623458725423456, 466453000000000452) << endl;
    return 0;
}

