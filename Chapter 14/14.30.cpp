/**
 * Exercise 14.30 为你的StrBlobPtr分别添加解引用运算符和箭头运算符
 */
#include <iostream>
#include <string>
#include "../common/header/StrBlob.h"
#include "../common/header/StrBlobPtr.h"

using namespace std;

int main() {

    StrBlob sb{"hello", "world"};
    StrBlobPtr sbp(sb);
    const StrBlobPtr csbp(sb);
    cout << "-----------test '*'------------" << endl;
    cout << *sbp << endl;
    cout << "-----------test '->'------------" << endl;
    cout << csbp->size() << endl;

    return 0;
}

