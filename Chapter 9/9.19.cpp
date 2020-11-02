/**
 * Exercise 9.19 编写程序，从标准输入读取string 蓄力，存入一个list中，然后用迭代器打印list的元素
 */
#include <iostream>
#include <list>

using namespace std;


int main(int argc, char **argv) {
    list<string> l_str;
    cout << "请输入五个字符串:" << endl;
    for (auto i = 0; i < 5; ++i) {
        string str;
        cin >> str;
//        l_str.push_front(str);
        l_str.push_back(str);
    }
    auto begin = l_str.cbegin();
    while (begin != l_str.cend()) {
        cout << *begin++ << endl;
    }
    return 0;
}


