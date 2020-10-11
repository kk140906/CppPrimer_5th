/*
 * Exercise 12.26 使用allocator重写p427的程序
 *
 * */

#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;


int main(int argc, char **argv) {
    allocator<string> alloc_str;
    size_t size = 5, count = 0;
    auto p = alloc_str.allocate(size), q = p;
    string str;
    cout << "请输入5个字符串:" << endl;
    while (count++ < size && cin >> str) {
        alloc_str.construct(q++, str);
    }
    cout << "输入的字符串内容为:" << endl;
    while (q != p) {
        cout << *--q << " ";
        alloc_str.destroy(q);
    }
    alloc_str.deallocate(p, size);
    cout << endl;
    return 0;
}




