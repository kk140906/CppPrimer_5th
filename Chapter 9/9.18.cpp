/**
 * Exercise 9.18 编写程序，从标准输入读取string 蓄力，存入一个deque中，然后用迭代器打印deque的元素
 */
#include <iostream>
#include <deque>

using namespace std;


int main(int argc, char **argv) {
    deque<string> d_str;
    cout << "请输入五个字符串:" << endl;
    for (auto i = 0; i < 5; ++i) {
        string str;
        cin >> str;
        d_str.push_back(str);
    }
    auto begin = d_str.cbegin();
    while (begin != d_str.cend()) {
        cout << *begin++ << endl;
    }
    return 0;
}


