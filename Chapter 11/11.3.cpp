/**
 * Exercise 11.3-11.4 编写一个单词计数程序，可以忽略大小写和标点，例如"example.","Example,","example?"等单词应该递增相同的计数器
 * */
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void erasePunctuation(string &str) {
    string punctuation(",.;?!");
    auto pos = 0;
    while ((pos = str.find_first_of(punctuation, pos)) != string::npos) {
        str.erase(pos, 1);
    }
}

int main(int argc, char **argv) {
    cout << "请输入一系列单词：" << endl;
    map<string, string::size_type> words_count;
    string word;
    while (cin >> word) {
        erasePunctuation(word);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        ++words_count[word];
    }
    for_each(words_count.cbegin(), words_count.cend(),
             [](const auto &w) { cout << w.first << "出现 " << w.second << " 次" << endl; });
    return 0;
}


