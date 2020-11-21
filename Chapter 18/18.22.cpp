/**
 * @details: Exercise 18.22
 * @details: Exercise 18.23
 */
#include <iostream>

using namespace std;

class A {
public:
    A() { cout << __func__ << endl; }
};

class B : public A {
public:
    B() { cout << __func__ << endl; }
};

class C : public B {
public:
    C() { cout << __func__ << endl; }
};

class X {
public:
    X() { cout << __func__ << endl; }
};

class Y {
public:
    Y() { cout << __func__ << endl; }
};

class Z : public X, public Y {
public:
    Z() { cout << __func__ << endl; }
};

class MI : public C, public Z {
public:
    MI() { cout << __func__ << endl; }
};

class D : public X, public C {
public:
    D() { cout << __func__ << endl; }
};

int main() {
    MI m;

    D *pd = new D;

    // (a)
    X *px = pd;
    // (b)
    A *pa = pd;
    // (c)
    B *pb = pd;
    // (d)
    C *pc = pd;

    return 0;
}

