/*
 * Exercise 6.25 编写一个main函数，接收两个实参,并把两个实参连接成一个string对象输出
 */
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    std::cout << "Hello, World!" << std::endl;
    string str1 = argv[1];
    string str2 = argv[2];
    cout << str1 + str2 << endl;
    return 0;
}

