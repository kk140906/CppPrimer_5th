/*
 * Exercise 14.26 为你的StrBlob,StrBlobPtr,StrVec,Strings类定义下标运算符
 */
#include <iostream>
#include <string>
#include "../common/header/StrVec.h"
#include "../common/header/StrBlob.h"
#include "../common/header/StrBlobPtr.h"
#include "../common/header/String.h"

using namespace std;

int main() {

    StrVec sv1{"hello", "world"};
    StrBlob sb{"hello", "world"};
    StrBlobPtr sbp(sb);
    Strings str("hello");
    cout << sv1[0] << " " << sb[0] << " " << sbp[0] << " " << str[0] << endl;

    return 0;
}

