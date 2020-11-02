/**
 * Exercise 9.26 将一个数组分别拷贝到一个vector和list中，
 * 使用erase接收单个迭代器的版本删除对应的元素，vector中仅保留奇数，list中仅保留偶数
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char **argv) {
    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v_int;
    list<int> l_int;
    for (auto ia : a) {
        v_int.push_back(ia);
        l_int.push_back(ia);
    }

    auto v_begin = v_int.begin();
    auto l_begin = l_int.begin();

    while (v_begin != v_int.end()) {
        // 注意当没有找到要处理的数据时迭代器不会更新
        if (!(*v_begin % 2)) {
            v_begin = v_int.erase(v_begin);
        } else {
            ++v_begin;
        }
    }
    while (l_begin != l_int.end()) {
        if (*l_begin % 2) {
            l_begin = l_int.erase(l_begin);
        } else {
            ++l_begin;
        }
    }
    cout << "vector中元素为:" << endl;
    for (const auto &iv : v_int) {
        cout << iv << " ";
    }
    cout << endl;
    cout << "list中元素为:" << endl;
    for (const auto &il : l_int) {
        cout << il << " ";
    }
    cout << endl;
    return 0;
}


