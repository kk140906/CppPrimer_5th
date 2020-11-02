/**
 * Exercise 6.17 编写一个函数判断string 对象中是否含有大写字母，再编写一个函数把string对象全部改为小写
 */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isContainUpper(const string &str);

void allToUpper(string &str);

int main() {
    std::cout << "Hello, World!" << std::endl;
    string test = "Hello,World";
    cout << isContainUpper(test) << endl;
    allToUpper(test);
    cout << test << endl;
    return 0;
}

bool isContainUpper(const string &str) {
    for (auto c : str) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
//    C++ 11新特性
//    return std::any_of(str.cbegin(), str.cend(), ::isupper);
}

void allToUpper(string &str) {
    for (auto &c : str) {
        if (isupper(c)) {
            c = tolower(c);
        }
    }
}

