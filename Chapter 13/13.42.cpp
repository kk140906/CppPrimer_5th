/*
 * Exercise 13.42 在TextQuery 和TextQueryResult类中使用StrVec代替vector<string>来测试StrVec类
 */


#include <iostream>
#include <string>
#include <algorithm>
#include "13.42.textquery.h"
#include "13.42.textqueryresult.h"

using namespace std;
using namespace Exercise1342;

int main(int argc, char **argv) {

    string file("Chapter 12/12.27.testFile.txt");
    TextQuery textQuery(file);
    string word;
    while (true) {
        cout << "请输入需要查询的单词:" << endl;
        cin >> word;
        auto result = textQuery.query(word);
        result.print();
        cout << endl;
        for_each(result.begin(), result.end(), [](const auto &cr) { cout << cr << " "; });
        cout << endl;
        cout << *result.begin() << " " << *result.end() << endl;
        cout << "文件行数:" << result.get_file()->size() << endl;
    }
    return 0;
}




