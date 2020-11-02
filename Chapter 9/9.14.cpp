/**
 * Exercise 9.14 将一个list中的char * 指针传递给vector中的string
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;


int main(int argc, char **argv) {
    // 最新的C++不允许直接使用字符串常量去初始化 char *
    char a[] = "hello", b[] = "world";
    list<char *> l_str{a, b};
    // 字符串常量只能去初始化 const char *
    list<const char *> l_cstr{"hello", "world"};
    vector<string> v_str(l_str.cbegin(), l_str.cend());
    for (const auto &vs : v_str) {
        cout << vs << endl;
    }
    return 0;
}


