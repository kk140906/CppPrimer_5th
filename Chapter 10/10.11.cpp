/*
 * Exercise 10.11 实现一个函数使一个序列没有重复元素,使用stable_sort代替sort
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print(vector<string> &v_str) {
    for (const auto &v : v_str) {
        cout << v << " ";
    }
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void eraseDuplicate(vector<string> &v_str) {
    cout << "原始容器元素:" << endl;
    print(v_str);
    cout << endl;
    // 对容器元素进行重排
    sort(v_str.begin(), v_str.end());
    cout << "排序后容器元素:" << endl;
    print(v_str);
    cout << endl;
    // 将unique只对临近元素进行去重操作，因此必须排序后再重排，重复元素移动到序列的后部
    auto end_unique = unique(v_str.begin(), v_str.end());
    cout << "重排后容器元素:" << endl;
    print(v_str);
    cout << endl;
    // 删除元素
    v_str.erase(end_unique, v_str.end());
    cout << "删除后容器元素:" << endl;
    print(v_str);
    cout << endl;
}

int main(int argc, char **argv) {
    vector<string> v_str{"hello", "run", "world", "aa", "aa", "and", "the", "vector", "and"};
    eraseDuplicate(v_str);
    // 使用谓词保证已经按照字典排序的序列按在大小排列
    stable_sort(v_str.begin(), v_str.end(), isShorter);
    cout << "按大小排序后:" << endl;
    print(v_str);
    return 0;
}


