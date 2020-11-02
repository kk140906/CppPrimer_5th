/** Exercise 12.28 编写单词查询程序，读取给定文件的内容，然后根据给定的字符串查询该字符串在给定文件中出现的次数及其对应行数
 * 不要使用类进行操作，直接使用vector,map,set等容器来保存来自文件的数据并生成查询结果
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;


vector<string> read(const string &filename) {
    vector<string> contents;
    string lines;
    ifstream in_file(filename);
    if (!in_file) {
        cout << filename << "-打开失败." << endl;
        exit(-1);
    }
    while (getline(in_file, lines)) {
        contents.push_back(lines);
    }
    return contents;
}

map<string, set<size_t>> extractWord(const vector<string> &vec) {
    map<string, set<size_t>> table;
    size_t count = 0;
    for (const auto &cv : vec) {
        istringstream stream(cv);
        string word;
        while (stream >> word) {
            table[word].insert(count);
        }
        ++count;
    }
    return table;
}

pair<string, vector<pair<size_t, string>>>
query(const map<string, set<size_t>> &table, const vector<string> &contents, const string &str) {
    auto values = table.find(str);
    pair<string, vector<pair<size_t, string>>> result;
    if (values != table.end()) {
        auto second = values->second;
        for_each(second.begin(), second.end(),
                 [&result, contents](const auto &cs) mutable {
                     result.second.push_back(pair<size_t, string>(cs, contents[cs]));
                 });
    }
    result.first = str;
    return result;
}

void print(ostream &os, const pair<string, vector<pair<size_t, string>>> &result) {
    os << result.first << " occurs " << result.second.size() << " times." << endl;
    for (const auto &cv : result.second) {
        os << "(line " << cv.first + 1 << " ) " << cv.second << endl;
    }
}

int main(int argc, char **argv) {
    string file = "Pride_And_Prejudice.txt";
    auto contents = read(file);
    auto table = extractWord(contents);
    string word;
    while (word != "quit") {
        cout << "请输入需要查询的单词:" << endl;
        cin >> word;
        auto result = query(table, contents, word);
        print(cout, result);
    }
    return 0;
}




