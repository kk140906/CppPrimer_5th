/**
 * Exercise 5.14 编写一段程序，从标准输入中读取若干string对象，并查找连续重复出现的单词。
 * 输出重复次数最多的单词及其重复次数，如果没有发现连续重复的单词则输出“没有发现连续单词！”
 */

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    std::cout << "Hello, World!" << std::endl;
    string word, maxDuplicateWord;
    vector<string> wordsVector;
    decltype(wordsVector.size()) curCnt = 1, maxCnt = 1;
    while (cin >> word && word != "q") {
        if (wordsVector.size() >= 1) {
            auto tailData = --wordsVector.cend();
            if (word == *tailData) {
                ++curCnt;
                if (curCnt > maxCnt) {
                    maxCnt = curCnt;
                    maxDuplicateWord = *tailData;
                }
            } else {
                curCnt = 1;
            }
        }
        wordsVector.push_back(word);
    }
    if (maxCnt > 1) {
        cout << maxDuplicateWord << "连续重复出现" << maxCnt << "次" << endl;
    } else {
        cout << "没有发现连续重复出现的单词!" << endl;
    }
    return 0;
}
