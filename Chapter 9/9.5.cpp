/**
 * Exercise 9.5 编写函数 接受一堆指向vector<int>的迭代器和一个int值
 * 在两个迭代器范围中查找给定的值，返回所找到的元素的迭代器，如果未找到返回一个尾后迭代器
 * */
#include <iostream>
#include <vector>

using namespace std;

using vi_cit = vector<int>::const_iterator;

// 不能将迭代器形参定义为引用，因为函数仅用于查找，不用于修改迭代器指向的元素类型
// 定义为常迭代类型较为合适，如果定义为引用意味着函数内可以通过该引用修改迭代器指向的元素类型，发生冲突
vi_cit findInt(vi_cit b, vi_cit e, int val);

int main(int argc, char **argv) {
    vector<int> vi({1, 2, 3, 4, 5});
    int val = 2;
    auto result = findInt(vi.cbegin(), vi.cend(), val);
    if (result != vi.cend()) {
        cout << "查找到元素:" << *result << endl;
    } else {
        cout << "没有找到元素:" << val << endl;
    }
    return 0;
}

vi_cit findInt(vi_cit b, vi_cit e, int val) {
    while (b != e) {
        if (*b++ == val) {
            // 由于判断后迭代器b已经指向下一个位置，而实际需要的返回的迭代器在上一个位置
            return --b;
        }
    }
    return b;
}
