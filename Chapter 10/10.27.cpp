/**
 * Exercise 10.27 标准库定义了unique_copy函数，它接受三个迭代器，表示拷贝一个迭代器范围中不重复元素到另一个迭代器；
 * 编写一个程序，使用unique_copy将一个vector中不重复的元素拷贝到一个初始为空的list中
 * */
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void eraseDuplicate(vector<int> &v_int) {
    sort(v_int.begin(), v_int.end(), [](const int &v1, const int &v2) { return v1 <= v2; });
    auto end_iterator = unique(v_int.begin(), v_int.end());
    v_int.erase(end_iterator, v_int.end());
}

int main(int argc, char **argv) {
    vector<int> v_int{1, 1, 3, 4, 5, 2, 3, 4, 5, 2, 5, 6};
    eraseDuplicate(v_int);
    list<int> l_int;
    unique_copy(v_int.cbegin(), v_int.cend(), back_inserter(l_int));
    for_each(l_int.cbegin(), l_int.cend(), [](const int &i) { cout << i << endl; });
    return 0;
}


