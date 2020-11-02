/**
 * Exercise 9.25 erase接收两个迭代器的版本接收两个相同的迭代器或者接受尾后迭代器的结果
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    vector<int> v_int{2, 6, 3, 4, 6, 4, 56, 9};
    auto begin = v_int.cbegin();
    auto end = v_int.cend();
    // 接收两个相同的迭代器，将返回接收的迭代器
    auto it1 = v_int.erase(begin + 1, begin + 1);
    cout << *it1 << endl;
    // 接收两个相同的尾后迭代器，将返回尾后迭代器
    auto it2 = v_int.erase(end, end);
    cout << *--it2 << endl;

    return 0;
}


