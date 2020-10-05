/*
 * Exercise 9.21 编写程序，从一个list<int>拷贝元素到deque中，偶数拷贝到一个deque，奇数拷贝到另一个deque中
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    int i;
    vector<int> v_int;
    auto begin = v_int.cbegin();
    cout << "请输入需要保存到vector中的数值：" << endl;
    while (cin >> i) {
        begin = v_int.insert(begin, i);
    }
    cout << "vector中保存的数值为：" << endl;
    for (const auto &ii : v_int) {
        cout << ii << endl;
    }
    return 0;
}


