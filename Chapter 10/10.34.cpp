/**
 * Exercise 10.34 使用reverse_iterator迭代器逆序打印一个vector
 * Exercise 10.35 使用普通迭代器逆序打印一个vector
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    vector<int> v_int{1, 2, 3, 4, 5, 6};
    cout << "使用反向迭代器逆序打印vector:" << endl;
    for_each(v_int.crbegin(), v_int.crend(), [](const int &ci) { cout << ci << " "; });
    cout << endl;
    cout << "使用普通迭代器逆序打印vector:" << endl;
    for (auto cend = v_int.cend(), cbegin = v_int.cbegin(); cend != cbegin;) {
        cout << *--cend << " ";
    }
    cout << endl;
    cout << "使用反向迭代器的base成员函数逆序打印vector:" << endl;
    for (auto cend = v_int.crbegin().base(), cbegin = v_int.crend().base(); cend != cbegin;) {
        cout << *--cend << " ";
    }
    cout << endl;
    return 0;
}


