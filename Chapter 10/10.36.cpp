/**
 * Exercise 10.36 使用find在一个int的list中查找最后一个值为0的元素位置
 * */
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(int argc, char **argv) {
    list<int> l_int{1, 3, 3, 5, 5, 2};
    auto cbegin = l_int.crbegin(), cend = l_int.crend();
    auto reverse_iterator_last = find(cbegin, cend, 0);
    // 由于list底层数据结构是双向链表，不支持两个迭代器之间的算术运算，因此如果要知道位置需要再遍历一次计算出现的位置
    int pos = 0;
    for_each(l_int.cbegin(), reverse_iterator_last.base(), [&pos](const int &i)mutable { ++pos; });
    cout << "最后一个数值0出现在list第 " << pos << " 个位置" << endl;
    // distance可以计算两个迭代器之间的距离,函数原型是第一个迭代器不停的++直到等于第二个迭代器为止，
    // 由于传入的迭代器是反向迭代器，因此第二个参数仍为尾后迭代器
    cout << "最后一个数值0出现在list第 " << distance(reverse_iterator_last, cend) << " 个位置" << endl;
    return 0;
}


