/**
 * Exercise 5.20 编写一段程序，从标准输入中读取string内容直到读取到两个相同的单词或者所有单词都读取完毕为止
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string curWord, preWord;
    bool isDuplicated = false;
    cout << "请输入字符串：" << endl;
    while (cin >> curWord) {
        if (curWord == preWord) {
            cout << curWord << "连续重复两次" << endl;
            isDuplicated = true;
            break;
        }
        preWord = curWord;
    }
    if (!isDuplicated) {
        cout << "没有发现连续重复出现的单词" << endl;
    }
    return 0;
}
