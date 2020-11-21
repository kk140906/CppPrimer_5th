/**
 * @details: Exercise 18.29 有以下继承关系，回答下列问题
 *                          (a)当作用于一个Final对象时，构造函数和析构函数的执行次序分别是什么
 *                          (b)在Final对象中，有几个Base部分，有几个Class部分
 *                          (c)下面的哪些赋值操作会造成编译错误
 *                          Base *pb; Class *pc; MI *pmi; D2 *pd2;
 *                          (1)pb = new Class; (2)pc = new Final;
 *                          (3)pmi = pb;       (4)pd2 = pmi;
 */
#include <iostream>
#include <string>

using namespace std;

struct Class {
    Class() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual ~Class() { cout << __PRETTY_FUNCTION__ << endl; }
};

struct Base : public Class {
    Base() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual ~Base() { cout << __PRETTY_FUNCTION__ << endl; }
};

struct D1 : virtual public Base {
    D1() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual ~D1() { cout << __PRETTY_FUNCTION__ << endl; }
};

struct D2 : virtual public Base {
    D2() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual ~D2() { cout << __PRETTY_FUNCTION__ << endl; }
};

struct MI : public D1, public D2 {
    MI() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual ~MI() { cout << __PRETTY_FUNCTION__ << endl; }
};

struct Final : public MI, public Class {
    Final() { cout << __PRETTY_FUNCTION__ << endl; }

    virtual ~Final() { cout << __PRETTY_FUNCTION__ << endl; }
};


int main() {
    Final final;
    // 从类的构造和析构可以看到在一个Final对象中，Base由于虚继承只有一个，而Class非虚继承因此有两个。

    Base *pb;
    Class *pc;
    MI *pmi;
    D2 *pd2;
//    (1) Base是Class的派生类，不能将派生类类型的指针指向基类对象
//    pb = new Class;
//    (2) 在Final对象中存在两个Class，因此该指针不知道指向哪个Class,发生二义性
//    pc = new Final;
//    (3) 不能进行虚基类的指针向派生类指针类型转换
//    pmi = pb;
//    (4) 合法，派生类指针向基类指针转换
    pd2 = pmi;
    return 0;
}

