/**
 * Exercise 9.43 编写一个函数，接受三个string参数,oldVal,newVal,
 * 使用迭代器及insert和erase函数将s中的oldVal替换为newVal,测试程序，用它替换通用的简写形式
 * 例如"tho" 替换 "though","thru" 替换"through"
 */
#include <iostream>
#include <string>

using namespace std;

void replaceWord(string &s, const string &oldVal, const string &newVal);


int main(int argc, char **argv) {
    string str1("hello");
    cout << "替换前:" << str1 << endl;
    replaceWord(str1, "hello", "ruo");
    cout << "替换后:" << str1 << endl;
    string str2("tho tho tho!th");
    cout << "替换前:" << str2 << endl;
    replaceWord(str2, "tho", "though");
    cout << "替换后:" << str2 << endl;
    return 0;
}

void replaceWord(string &s, const string &oldVal, const string &newVal) {
    auto old_size = oldVal.size(), new_size = newVal.size();
    // s字符串大小小于oldVal的大小，必然不会存在符合的字符串，或者oldVal为空，直接返回
    if (s.size() < old_size || !old_size) {
        return;
    }
    // 迭代器范围属于左闭右开区间,迭代器从0开始计数，
    // 而begin + old_size导致迭代器多移动了一次,因此可以等于尾后迭代器了
    // 定义begin 为const iterator，不会通过begin直接去修改s的值，而是通过erase和insert去修改的
    for (auto begin = s.cbegin(); begin + old_size <= s.cend(); ++begin) {
        // 先比较一下，s中找到与oldVal第一个字符相等的情况下才会去比较后续的字符
        if (*begin == *oldVal.begin()) {
            // 迭代器范围属于左闭右开区间,迭代器从0开始计数，
            string sub_s(begin, begin + old_size);
            if (sub_s == oldVal) {
                // 迭代器范围属于左闭右开区间,迭代器从0开始计数，erase操作返回的是删除后的第一个元素的迭代器
                begin = s.erase(begin, begin + old_size);
                // 跳过新插入的字符数串，insert操作后返回的迭代器指向插入的第一个元素位置，而迭代器从0开始计数
                // 加nwe_size刚好使迭代器移动到插入之前的位置
                begin = s.insert(begin, newVal.cbegin(), newVal.cend()) + new_size;
            }
        }
    }
}


