/*
 * Exercise 12.33 在TextQueryResult类中添加名为begin和end的成员，返回一个迭代器，指向查询行号结果的set中的某个位置
 * 再添加一个名为get_file的成员，返回一个shared_ptr，指向TextQueryResult中包含文件所有内容的vector
 * */

#include <iostream>
#include <string>
#include <algorithm>
#include "12.33.textquery.h"
#include "12.33.textqueryresult.h"

using namespace std;
using namespace Exercise1233;

int main(int argc, char **argv) {

    string file("12.27.testFile.txt");
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




