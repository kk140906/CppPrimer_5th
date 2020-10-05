/*
 * Exercise 9.41 利用一个vector<char> 去初始化一个string
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    vector<char> v_ch{'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    // 使用vector::data()获取容器内所有元素
    // 初始化string使用的构造函数是 string str(cp,n),其中cp是字符数组或者字符序列，n表示大小
    string str1(v_ch.data(), v_ch.size());
    cout << str1 << endl;
    // 使用迭代器构造
    string str2(v_ch.cbegin(), v_ch.cend());
    cout << str2 << endl;
    return 0;
}



