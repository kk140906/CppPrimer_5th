/**
 * @details: Exercise 18.25 两个基类Base1和Base2，各自定义了一个名为print的虚成员函数和虚析构函数，然后派生出D1，D2，MI，
 *                          通过指针,指明每个调用中分别使用了哪个函数
 *
 */
#include <iostream>

using namespace std;

class Base1 {
public:
    virtual void print() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual ~Base1(){ cout << __PRETTY_FUNCTION__ << endl; }
};

class Base2 {
public:
    virtual void print() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual ~Base2(){ cout << __PRETTY_FUNCTION__ << endl; }
};

class D1 : public Base1 {
public:
    virtual void print() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual  ~D1(){ cout << __PRETTY_FUNCTION__ << endl; }
};

class D2 : public Base2 {
public:
    virtual void print() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual  ~D2(){ cout << __PRETTY_FUNCTION__ << endl; }
};

class MI : public D1, public D2 {
public:
    virtual void print() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual  ~MI(){ cout << __PRETTY_FUNCTION__ << endl; }
};

int main() {
    Base1 *pb1 = new MI;
    Base2 *pb2 = new MI;
    D1 *pd1 = new MI;
    D2 *pd2 = new MI;

    // (a)
    pb1->print();
    // (b)
    pd1->print();
    // (c)
    pd2->print();
    cout << endl;
    // (d)
    delete pb2;
    cout << endl;
    // (e)
    delete pd1;
    cout << endl;
    // (f)
    delete pd2;

    return 0;
}

