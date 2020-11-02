/**
 * Exercise 14.38 编写一个类，令其检查某个给定string对象的长度是否与一个阈值相等。
 * 使用该对象编写程序，统计并报告在输入的文件中长度为1的单词有多少个，长度为2的单词有多少个，。。。。。长度为10的单词有少个
 * Exercise 14.39 修改上一题，令其报告1至9之间的单词共有多少个，长度在10以上的单词又有多少个
 */
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>

using namespace std;

struct Equals {
    Equals() = default;

    Equals(std::size_t n) : len(n) {}

    // 以string作为参数传递更为合适，只要需要构造一次Equals对象
    // 如果传递的是string的长度，那么就意味在比较的时候需要创建多个Equals的对象与传递的长度进行比较
    bool operator()(const string &rs) {
        return rs.length() == len;
    }

private:
    size_t len;
};

struct Bigger {

    Bigger(std::size_t n) : len(n) {}

    bool operator()(const string &rs) {
        return rs.length() > len;
    }

private:
    size_t len;
};

struct Range {

    Range(std::size_t min, std::size_t max) : len_min(min), len_max(max) {}

    bool operator()(const string &rs) {
        return rs.length() >= len_min && rs.length() <= len_max;
    }

private:
    size_t len_min;
    size_t len_max;
};

int main() {
    auto start = GetTickCount();
    ifstream in("Pride_And_Prejudice.txt");
    if (!in) {
        cout << "file don't exist.";
    }
    string line;
    vector<string> vs;
    while (getline(in, line)) {
        istringstream is(line);
        string word;
        while (is >> word) {
            vs.push_back(word);
        }
    }
    for (auto i = 1; i <= 10; ++i) {
        Equals eq(i);
        cout << "单词长度为 " << i << " 的个数为: " << count_if(vs.begin(), vs.end(), eq) << endl;
    }
    Range rg(1, 9);
    cout << "单词长度在 1-9 的个数为: " << count_if(vs.begin(), vs.end(), rg) << endl;
    Bigger bg(10);
    cout << "单词长度超过 10 的个数为: " << count_if(vs.begin(), vs.end(), bg) << endl;
    cout << "总计耗时: " << GetTickCount() - start << " ms" << endl;
    return 0;
}

