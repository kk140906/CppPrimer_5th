/*
 * Exercise 14.32 定义一个类，令其含有指向StrBlobPtr对象的指针，为这个类定义重载的箭头运算符
 */
#include <iostream>
#include <string>
#include "../common/header/StrBlob.h"
#include "../common/header/StrBlobPtr.h"

using namespace std;

class Ptr {
public:
    Ptr(StrBlobPtr *sbp) : p_sbp(sbp) {}

    StrBlobPtr operator->() const {
        return *p_sbp;
    }

private:
    StrBlobPtr *p_sbp;
};

int main() {

    StrBlob sb{"hello", "world"};
    StrBlobPtr sbp(sb);
    const StrBlobPtr csbp(sb);
    Ptr p_sbp(&sbp);
    cout << "-----------test '*'------------" << endl;
    cout << *sbp << endl;
    cout << "-----------test '->'------------" << endl;
    cout << p_sbp->size() << endl;

    return 0;
}

