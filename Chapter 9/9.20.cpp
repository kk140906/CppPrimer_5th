/**
 * Exercise 9.20 编写程序，从一个list<int>拷贝元素到deque中，偶数拷贝到一个deque，奇数拷贝到另一个deque中
 */
#include <iostream>
#include <list>
#include <deque>

using namespace std;


int main(int argc, char **argv) {
    list<int> l_int{1, 3, 2, 56, 20, 33, 435};
    deque<int> d_even;
    deque<int> d_odd;
    const unsigned flag = 1;
    // 可以通过迭代器遍历list中所有元素
    for (const auto &l : l_int) {
        // 也可以对2取余来判断奇偶数
        if (l & flag) {
            d_odd.push_back(l);
        } else {
            d_even.push_back(l);
        }
    }
    cout << "偶数队列中的元素为：" << endl;
    for (const auto &d : d_even) {
        cout << d << endl;
    }
    cout << "奇数队列中的元素为：" << endl;
    for (const auto &d : d_odd) {
        cout << d << endl;
    }
    return 0;
}


