/*
 * Exercise 14.27 为你的StrBlobPtr添加递增和递减运算符
 * Exercise 14.28 为你的StrBlobPtr添加加法和减法的运算符，使其可以实现指针的运算
 */
#include <iostream>
#include <string>
#include "../common/header/StrBlob.h"
#include "../common/header/StrBlobPtr.h"

using namespace std;

int main() {

    StrBlob sb{"hello", "world"};
    StrBlobPtr sbp(sb);
    cout << "-----------test '++'------------" << endl;
    cout << *++sbp << endl;
    cout << "-----------test '--'------------" << endl;
    cout << *--sbp << endl;
    cout << "-----------test '+'------------" << endl;
    cout << *(sbp + 1) << endl;
    cout << "-----------test '+'------------" << endl;
    cout << *(++sbp - 1) << endl;
    return 0;
}

