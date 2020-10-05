/*
 * Exercise 10.20 标准库中定义了一个名为count_if的算法，该算法接受一个迭代器范围，还接受一个谓词，会对输入范围中的每个元素执行。
 * 该算法返回一个计数值，表示谓词有多少次为真，使用count_if重写统计有多少单词长度超过3的部分
 * */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    vector<string> v_str{"hh", "haha", "run", "run", "add", "hh", "hello", "world", "kk"};
    string::size_type size = 3;
    cout << "单词长度至少为" << size << "的个数为：\n"
         << count_if(v_str.cbegin(), v_str.cend(), [size](const string &str) { return str.size() >= size; });
    return 0;
}


