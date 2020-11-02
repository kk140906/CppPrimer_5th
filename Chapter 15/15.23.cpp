/**
 * Exercise 15.23 假设P550的D1类需要隐藏它继承而来的fcn函数，应该如何修改，修改书中的调用应该如果解析
 */
#include <iostream>
#include "../common/header/Quote.h"

using namespace std;

class Base {
public:
    virtual int fcn() {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }
};

class D1 : public Base {
public:
    int fcn() override {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }

    int fcn(int) {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }

    virtual void f2() { cout << __PRETTY_FUNCTION__ << endl; }
};

class D2 : public D1 {
public:
    int fcn(int) {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }

    int fcn() {
        cout << __PRETTY_FUNCTION__ << endl;
        return 0;
    }

    void f2() { cout << __PRETTY_FUNCTION__ << endl; }
};

int main() {
    Base b_obj;
    D1 d1_obj;
    D2 d2_obj;
    Base *bp1 = &b_obj, *bp2 = &d1_obj, *bp3 = &d2_obj;
    // 调用base的fcn
    bp1->fcn();
    // 调用D1的fcn
    bp2->fcn();
    // 调用D2的fcn
    bp3->fcn();

    D1 *d1p = &d1_obj;
    D2 *d2p = &d2_obj;
    // base没有f2成员函数
//    bp2->f2();

    // 调用D1的f2
    d1p->f2();
    // 调用D2的f2
    d2p->f2();

    Base *p1 = &d2_obj;
    D1 *p2 = &d2_obj;
    D2 *p3 = &d2_obj;
    // base 没有带参数的fcn
//    p1->fcn(42);
    // 带参数的fcn不是虚函数，调用D1的fcn
    p2->fcn(42);
    // 带参数的fcn不是虚函数，调用D2的fcn
    p3->fcn(42);
    return 0;
}

