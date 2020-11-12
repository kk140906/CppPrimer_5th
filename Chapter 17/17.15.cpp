/**
 * @details: Exercise 17.15 编写程序，使用模式查找违反"i除非在c之后，否则必须在e之前"规则的单词，
 *           你的程序应该提示用户输入一个单词，然后指出单词是否符合要求。
 * @details: Exercise 17.16 regex对象使用"[^c]ei"进行初始化
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <regex>

using namespace std;

bool Check(const string &s) {
    // 模式要求的语句应该解析为两个方面：
    // i如果不在c在后，那么i必须在e之前
    // i如果在c之后，那么允许i在e之后
    regex r1("cei"), r2("[^c]ie");
    return regex_search(s, r1) || regex_search(s, r2);
}

bool Check2(const string &s) {
    regex r("[^c]ei");
    return regex_search(s, r);
}

int main() {
    string word;
    cout << "请输入单词:" << endl;
    while (cin >> word) {
        cout << word << ": ";
        if (Check(word)) {
            cout << "没有违反规则." << endl;
        } else {
            cout << "违反规则." << endl;
        }
        cout << "请输入单词:" << endl;
    }
    return 0;
}

