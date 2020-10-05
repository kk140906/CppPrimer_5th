/*
 * Exercise 10.25 对一个序列的字符串进行字典排序，去重操作，然后按照大小进行重排，
 * 打印输出比接收的长度参数长的字符串，用bind和check_size替换partition中的lambda表达式
 * */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

void eraseDuplicate(vector<string> &v_str) {
    // 对容器元素进行重排
    sort(v_str.begin(), v_str.end());
    // 将unique只对临近元素进行去重操作，因此必须排序后再重排，重复元素移动到序列的后部
    auto end_unique = unique(v_str.begin(), v_str.end());
    // 删除元素
    v_str.erase(end_unique, v_str.end());
}

bool check_size(const string &str, const string::size_type size) {
    return str.size() >= size;
}

void biggies(vector<string> &v_str, const string::size_type size) {
    // 去重，并按字典排序
    eraseDuplicate(v_str);
    // 稳定排序，按照字符串长度进行排序
    stable_sort(v_str.begin(), v_str.end(),
                [](const string &str1, const string &str2) { return str1.size() < str2.size(); });
    // partition会将符合条件的放在前部分，不符合条件的放在后部分,顺序就被打乱了
    auto iterator_last = partition(v_str.begin(), v_str.end(),
                                   bind(check_size, placeholders::_1, size));
    // 计算长度
    auto count = iterator_last - v_str.begin();
    cout << "count = " << count << endl;
    // 循环打印每个元素
    for_each(v_str.begin(), iterator_last, [](const string &str) { cout << str << " "; });
    cout << endl;
}

int main(int argc, char **argv) {
    vector<string> v_str{"hh", "haha", "run", "run", "add", "hh", "hello", "world", "kk"};
    biggies(v_str, 3);
    return 0;
}


