/*
 * Exercise 14.18 为你的StrBlob类、StrBlobPtr类，StrVec类，和Strings类定义关系运算符
 */
#include <iostream>
#include <string>
#include "../common/header/String.h"
#include "../common/header/StrVec.h"
#include "../common/header/StrBlob.h"
#include "../common/header/StrBlobPtr.h"

using namespace std;

int main() {
    cout << "--------StrBlob == Test------------" << endl;
    StrBlob sb1({"hello", "world"}), sb2({"hello", "aa"});
    cout << (sb1 < sb2) << endl;
    cout << "--------StrBlobPtr == Test------------" << endl;
    // {hello","word"}会隐式转换为StrBlob对象然后调用StrBlobPtr的构造函数，两个指向了不同的对象
    StrBlobPtr sbp1(sb1), sbp2({"hello", "word"}), sbp3(sb1);
    cout << (sbp1 < ++sbp3) << endl;
    cout << "--------Strings == Test------------" << endl;
    Strings s1("aad"), s2("aac");
    cout << (s1 < s2) << endl;
    cout << "--------StrVec == Test------------" << endl;
    StrVec sv1({"hello", "world"}), sv2({"aa", "77"});
    cout << (sv1 < sv2) << endl;
    return 0;
}

