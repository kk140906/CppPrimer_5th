
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;


map<string, string> readMappedTable(const string &file) {
    ifstream in_file(file);
    string line;
    map<string, string> mappedTable;
    while (getline(in_file, line)) {
        auto blank = line.find(" ");
        if (blank == string::npos) {
            break;
        }
        mappedTable[line.substr(0, blank)] = line.substr(blank + 1);
    }
    return mappedTable;
}

vector<string> readMappedWord(const string &file) {

    ifstream in_file(file);
    string word;
    vector<string> lineWords;
    while (getline(in_file, word)) {
        lineWords.push_back(word);
    }
    return lineWords;
}

vector<string> split(const string &str, const string &separate) {
    vector<string> words;
    vector<int> v_pos;
    int pos = 0, pre_pos = pos;
    while ((pos = str.find(separate, pos)) != string::npos) {
        string substr = str.substr(pre_pos, pos - pre_pos);
        if (!substr.empty()) {
            words.push_back(substr);
        }
        pre_pos = ++pos;
    }
    if (pre_pos < str.size()) {
        string substr = str.substr(pre_pos, str.size() - pre_pos);
        if (!substr.empty()) {
            words.push_back(substr);
        }
    }
    return words;
}


int main() {

    auto mappedTable = readMappedTable("11.33.mapRules.txt");
    auto mappedWord = readMappedWord("11.33.mappedFile.txt");
    for_each(mappedWord.cbegin(), mappedWord.cend(), [mappedTable](const auto &cw) {
        string result;
        for (const auto &w :split(cw, " ")) {
            result += mappedTable.find(w) == mappedTable.end() ? w + " " : mappedTable.at(w) + " ";
        }
        cout << result << endl;
    });

    return 0;
}
