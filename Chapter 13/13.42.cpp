/**
 * Exercise 13.42 在TextQuery 和TextQueryResult类中使用StrVec代替vector<string>来测试StrVec类
 */

#define Exercise1342

#include <iostream>
#include <string>
#include <algorithm>
#include "../common/header/text_query.h"
#include "../common/header/text_query_result.h"


using namespace std;

int main(int argc, char **argv) {

    string file("Pride_And_Prejudice.txt");
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
    }
    return 0;
}




