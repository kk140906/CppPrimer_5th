/*
 * Exercise 9.44 编写一个函数，接受三个string参数,oldVal,newVal,
 * 使用下标和replace函数将s中的oldVal替换为newVal,测试程序，用它替换通用的简写形式
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
    for (decltype(old_size) pos = 0; pos + old_size <= s.size(); ++pos) {
        if (s[pos] == oldVal[0]) {
            if (string(s, pos, old_size) == oldVal) {
                s.replace(pos, old_size, newVal);
                pos += new_size;
            }
        }
    }
}



