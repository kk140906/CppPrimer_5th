/**
 * Exercise 15.18
 * Exercise 15.19
 * Exercise 15.20
 */
#include <iostream>

using namespace std;

/**
 * 1. 只有派生类的继承方式为public时，类的外部用户才能使用派生类向基类的转换
 * 2. 派生类的内部成员和友元一定能够使用派生类向基类的转换
 * 3. 只有派生类的继承方式为public或者protected时，派生类的派生类内部成员和友元可以使用派生向基类的转换
 */
class Base {
public:
    void public_member();

protected:
    int protected_member;
private:
    char private_member;
};

struct Public_Derived : public Base {
    // 2. 派生类的内部成员和友元一定能够使用派生类向基类的转换
    void memfcn(Base &b) { b = *this; }

    int f() { return protected_member; }
};

struct Protected_Derived : protected Base {
    // 2. 派生类的内部成员和友元一定能够使用派生类向基类的转换
    void memfcn(Base &b) { b = *this; }

    int f1() const { return protected_member; }
};

struct Private_Derived : private Base {
    // 2. 派生类的内部成员和友元一定能够使用派生类向基类的转换
    void memfcn(Base &b) { b = *this; }

    int f2() const { return protected_member; }
};

struct Derived_from_public : public Public_Derived {
    // 3. 只有派生类的继承方式为public或者protected时，派生类的派生类内部成员和友元可以使用派生向基类的转换
    void memfcn(Base &b) { b = *this; }

    int f3() { return protected_member; }
};

struct Derived_from_protected : protected Protected_Derived {
    // 3. 只有派生类的继承方式为public或者protected时，派生类的派生类内部成员和友元可以使用派生向基类的转换
    void memfcn(Base &b) { b = *this; }

    int f4() const { return protected_member; }
};

struct Derived_from_private : private Private_Derived {
    // 3. 只有派生类的继承方式为public或者protected时，派生类的派生类内部成员和友元可以使用派生向基类的转换
//    void memfcn(Base &b) { b = *this; }
    // protected_member在Private_Derived中是私有成员，不能被派生类成员使用
//    int f5() const {return protected_member;}
};

int main() {

    // 1. 只有派生类的继承方式为public时，类的外部用户才能使用派生类向基类的转换
    Public_Derived d1;
    Private_Derived d2;
    Protected_Derived d3;
    // 正确，Public_Derived公有继承Base,派生类能正确向基类进行转换
    Base *p = &d1;
    // 错误，Private_Derived私有继承Base,派生类无法正确向基类进行转换
//    p = &d2;
    // 错误，Protected_Derived私有继承Base,派生类能正确向基类进行转换
//     p = &d3;

    Derived_from_public dd1;
    Derived_from_private dd2;
    Derived_from_protected dd3;

    p = &dd1;
//    p = &dd2;
//    p = &dd3;

    return 0;
}

