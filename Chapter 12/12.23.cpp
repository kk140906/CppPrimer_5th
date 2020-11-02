/**
 * Exercise 12.23 编写一个程序，连接接两个字符串字面常量，将结果保存在一个动态分配的char数组中
 * 然后重写这个程序，连接两个标准库的string对象
 * */

#include <cstring>
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <initializer_list>
#include <fstream>


using namespace std;

string join(const string &str1, const string &str2) {
    return str1 + str2;
}

char *join(const char *str1, const char *str2) {
    char *p = new char[strlen(str1) + strlen(str2) + 1];
    strcpy(p, str1);
    strcat(p, str2);
    return p;
}

int main(int argc, char **argv) {
    auto p = join("hello ", "world");
    cout << p << endl;
    delete[]p;

    cout << join(string("hello "), string("world")) << endl;
    return 0;
}


