/**
 * Exercise 14.35 编写一个类似于PrintString的类，
 * 令其从istream中读取一行输入，然后返回一个表示我们读取内容的string，如果读取失败，则返回空的string
 * Exercise 14.36 使用前一个练习的类读取标准输入的，将每一行保存为vector的一个元素
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WriteString {
public:
    string operator()(istream &is) {
        string contents;
        cout << "请输入内容:" << endl;
        if (getline(is, contents)) {
            return contents;
        }
        return string();
    }
};

int main() {

    WriteString ws;
    vector<string> vs;
    for (auto i = 0; i < 5; ++i) {
        vs.push_back(ws(cin));
    }
    for (const auto &cvs:vs) {
        cout << cvs << endl;
    }


    return 0;
}

