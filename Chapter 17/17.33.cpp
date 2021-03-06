/**
 * Exercise 17.33 编写程序，给定一个文件保存了一些规则，每条规则由两个部分组成，一个可能出现的关键词和一个用来替换它的短语
 * 而另一个文件保存了需要转换的文本，它根据规则文件中的匹配的多个规则中随机选择某个规则进行文本替换
 * 例如在规则文件中的内容为：y why
 * 在替换文件中的y应当被替换为why
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include <set>
#include <algorithm>
#include <sstream>
#include <random>
#include <functional>
#include <windows.h>
#include <ctime>

using namespace std;
using namespace std::placeholders;

// 由于允许多个规则，需要采用multimap
multimap<string, string> readMappedTable(const string &file) {
    ifstream in_file(file);
    if (!in_file) {
        cout << file << "-文件打开失败." << endl;
        return multimap<string, string>();
    }
    string line;
    multimap<string, string> mappedTable;
    while (getline(in_file, line)) {
        auto blank = line.find(' ');
        if (blank == string::npos || line.substr(blank + 1).empty()) {
            continue;
        }
        mappedTable.insert(std::pair<string, string>(line.substr(0, blank), line.substr(blank + 1)));
    }
    return mappedTable;
}

vector<string> readMappedWord(const string &file) {

    ifstream in_file(file);
    if (!in_file) {
        cout << file << "-文件打开失败." << endl;
        return vector<string>();
    }
    string word;
    vector<string> lineWords;
    while (getline(in_file, word)) {
        lineWords.push_back(word);
    }
    return lineWords;
}

vector<string> split(const string &str, const string &separator) {
    vector<string> words;
    vector<int> v_pos;
    int pos = 0, pre_pos = pos;
    while ((pos = str.find(separator, pos)) != string::npos) {
        string substr = str.substr(pre_pos, pos - pre_pos);
        if (!substr.empty()) {
            words.push_back(substr);
        }
        pre_pos = ++pos;
    }
    if (pre_pos < str.size()) {
        string substr = str.substr(pre_pos);
        if (!substr.empty()) {
            words.push_back(substr);
        }
    }
    return words;
}

vector<string> split(const string &str, const char &separator) {
    vector<string> words;
    string word;
    string tmp;
    // replace的目的是为了保证istringstream能够处理任意分隔字符
    // 算法不检查写操作，拷贝目的地的元素个数至少应该大于等于需要拷贝的元素个数
    // tmp为空，元素个数为0，不能直接使用其迭代器进行操作,可以利用resize将元素个数调整为需要拷贝的元素个数，就可以直接使用迭代器了
    // 使用back_inserter可以保证拷贝目的地的元素个数符合要求
//    tmp.resize(str.size());
//    replace_copy(str.cbegin(), str.cend(), tmp.begin(),separator, ' ');
    replace_copy(str.cbegin(), str.cend(), back_inserter(tmp), separator, ' ');
    istringstream str_stream(tmp);
    while (str_stream >> word) {
        words.push_back(word);
    }
    return words;
}

template<typename Func_1, typename Func_2>
void GenerateResult(multimap<string, string> &mappedTable, const string &cw, Func_1 &u, Func_2 &e) {
    string result;
    for (const auto &w :split(cw, ' ')) {
        size_t count = mappedTable.count(w);
        auto randi = u(e);
        auto max_it = count ? randi % count : count;
        auto bound = mappedTable.lower_bound(w);
        for (int i = 0; i < max_it; ++i) {
            ++bound;
        }
        result += mappedTable.count(w) ? bound->second + " " : w + " ";
    }
    cout << result << endl;
}

int main() {

    auto mappedTable = readMappedTable("17.33.mapRules.txt");
    auto mappedWord = readMappedWord("17.33.mappedFile.txt");
    // GetTickCount函数精度更高，尽可能可以保证下次运行时种子已经变化了
    default_random_engine e(GetTickCount());
    uniform_int_distribution<unsigned> u(0, 100);
    for_each(mappedWord.cbegin(), mappedWord.cend(),
             std::bind(GenerateResult<decltype(u), decltype(e)>, mappedTable, _1, u, e));
    return 0;
}
