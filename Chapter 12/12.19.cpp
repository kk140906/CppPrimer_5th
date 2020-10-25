/*
 * Exercise 12.19 定义自己的StrBlobPtr类，包含一个weak_ptr指向StrBlob的data成员
 * Exercise 12.20 逐行读取一个输入文件，将内容存入一个StrBlob中，用一个StrBlobPtr打印出StrBlob中所有元素
 * */

#include <iostream>
#include <memory>
#include <string>
#include <fstream>

#include "../common/header/StrBlob.h"
#include "../common/header/StrBlobPtr.h"

using namespace std;

int main(int argc, char **argv) {
    // make_shared 测试
    auto p1 = shared_ptr<string>();
    cout << "shared_ptr : p1 = " << p1 << " ,引用计数 : p1.use_count() = " << p1.use_count() << endl;
    auto p2 = make_shared<string>();
    cout << "make_shared : p2 = " << p2 << " ,引用计数 : p2.use_count() = " << p2.use_count() << endl;
    cout << endl;


    StrBlob b1, b3;
    cout << "push_back : a" << endl;
    b1.push_back("a");
    b3.push_back("tt");


    cout << "front: " << b1.front() << endl;
    cout << "back: " << b1.back() << endl;
    cout << "push_back : cc";
    b1.push_back("cc");
    cout << "front: " << b1.front() << endl;
    cout << "back: " << b1.back() << endl;
    for (auto iter = b1.begin(), end = b1.end(); iter != end; ++iter) {
        cout << *iter << " ";
    }
    cout << endl;


    string fileName("12.20.testFile.txt");
    ifstream in_file(fileName);
    if (!in_file) {
        cout << fileName << " 打开失败" << endl;
        return 0;
    }
    string word;
    StrBlob b2;
    while (getline(in_file, word)) {
        b2.push_back(word);
    }

    cout << endl;
    for (auto iter = b2.begin(), end = b2.end(); iter != end; ++iter) {
        cout << *iter << endl;
    }

    return 0;
}


