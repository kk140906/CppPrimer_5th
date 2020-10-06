/*
 * Exercise 11.31 定义一个作者及其作品的multimap，使用find在multimap中查找一个元素并用erase删除它，确保当元素不在map中也能正常运行
 * Exercise 11.32 按照字典序打印作者列表和他们的作品
 * */
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <utility>

using namespace std;


int main(int argc, char **argv) {
    multimap<string, string> authors;
    for (auto i = 0; i < 5; ++i) {
        authors.insert({"kk", to_string(i)});
    }

    for (auto i = 0; i < 5; ++i) {
        authors.insert({"gg", to_string(i)});
    }

    auto iter = authors.find("sk");
    if (iter != authors.end()) {
        authors.erase(iter);
    }

    iter = authors.find("gg");
    if (iter != authors.end()) {
        authors.erase(iter);
    }

    for (const auto &a : authors) {
        cout << a.first << " " << a.second << endl;
    }
    cout << endl;
    return 0;
}


