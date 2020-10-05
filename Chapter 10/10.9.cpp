/*
 * Exercise 10.9 实现一个函数使一个序列没有重复元素
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void print(vector<int> &v_int) {
    for (const auto &v : v_int) {
        cout << v << " ";
    }
}

void eraseDuplicate(vector<int> &v_int) {
    cout << "原始容器元素:" << endl;
    print(v_int);
    cout << endl;
    // 对容器元素进行重排
    sort(v_int.begin(), v_int.end());
    cout << "排序后容器元素:" << endl;
    print(v_int);
    cout << endl;
    // 将unique只对临近元素进行去重操作，因此必须排序后再重排，重复元素移动到序列的后部
    auto end_unique = unique(v_int.begin(), v_int.end());
    cout << "重排后容器元素:" << endl;
    print(v_int);
    cout << endl;
    // 删除元素
    v_int.erase(end_unique, v_int.end());
    cout << "删除后容器元素:" << endl;
    print(v_int);
    cout << endl;
}

int main(int argc, char **argv) {
    vector<int> v_int{1, 2, 3, 4, 5, 2, 3, 4, 2, 1, 2, 3, 4, 5};
    eraseDuplicate(v_int);
    return 0;
}


