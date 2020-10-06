/*
 * Exercise 11.8 在一个vector中保存不重复的单词
 * */
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

void addWord(vector<string> &words, const string &word) {
    if (any_of(words.cbegin(), words.cend(), [word](const auto &cw) { return cw == word; }))
        return;
    words.push_back(word);
}

int main(int argc, char **argv) {
    cout << "请输入一系列单词:" << endl;
    string word;
    vector<string> words;
    while (cin >> word) {
        addWord(words, word);
    }
    ostream_iterator<string> iterator_cout(cout, " ");
    cout << "容器中不重复的元素为:" << endl;
    copy(words.cbegin(), words.cend(), iterator_cout);
    cout << endl;
    return 0;
}


