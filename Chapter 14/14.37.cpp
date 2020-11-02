/**
 * Exercise 14.37 编写一个类令其检查两个值是否相等，使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Equals {
    Equals() = default;

    Equals(string str) : lhs(std::move(str)) {}

    bool operator()(const string &rhs) {
        return this->lhs == rhs;
    }

private:
    string lhs;
};


int main() {
    vector<string> vs{"hello", "world", "hello", "today"};
    string word = "hello";
    Equals eq(word);
    replace_copy_if(vs.begin(), vs.end(), vs.begin(), eq, "go");
    for (const auto &cv:vs) {
        cout << cv << endl;
    }

    return 0;
}

