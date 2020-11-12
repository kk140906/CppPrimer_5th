/**
 * @details: Exercise 17.17 查询所有违反“ei"规则的单词
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <regex>

using namespace std;


int main() {
    regex r1("\\w*cei\\w*"), r2("\\w*[^c]ie\\w*");

    vector<string> vs{"friend", "thief", "receipt", "receive"};
    smatch sm;
    for (const auto &ci: vs) {
        if (regex_search(ci, sm, r2)) continue;
        cout << ci << " ";
    }
    return 0;
}

