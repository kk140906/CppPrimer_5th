/**
 * Exercise 9.4 编写函数 接受一堆指向vector<int>的迭代器和一个int值
 * 在两个迭代器范围中查找给定的值，返回一个布尔值来指出是否找到
 * */
#include <iostream>
#include <vector>

using namespace std;

using vi_cit = vector<int>::const_iterator;

bool findInt(vi_cit b, vi_cit e, int val);

int main(int argc, char **argv) {
    vector<int> vi({1, 2, 3, 4, 5});
    int val = 5;
    if (findInt(vi.cbegin(), vi.cend(), val)) {
        cout << "查找到元素:" << val << endl;
    } else {
        cout << "没有找到元素:" << val << endl;
    }
    return 0;
}

bool findInt(vi_cit b, vi_cit e, int val) {
    while (b != e) {
        if (*b++ == val) {
            return true;
        }
    }
    return false;
}
