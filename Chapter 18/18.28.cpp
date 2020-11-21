/**
 * @details: Exercise 18.28 有以下继承关系，在VMI类的内部有哪些成员可以不使用限定符就能够直接访问的成员
 */
#include <iostream>
#include <string>

using namespace std;

struct Base {
    void bar(int) { cout << __PRETTY_FUNCTION__ << endl; }

protected:
    int ival = 42;
};

struct Derived1 : virtual public Base {
    void bar(char) { cout << __PRETTY_FUNCTION__ << endl; }

    void foo(char) { cout << __PRETTY_FUNCTION__ << endl; }

protected:
    char cval = '1';
};

struct Derived2 : virtual public Base {
    void foo(int) { cout << __PRETTY_FUNCTION__ << endl; }

protected:
    int ival = 5;
    char cval = '2';
};

class VMI : public Derived1, public Derived2 {
public:
    void func() {
        int i = 0;
        char c = 'a';
        //Derived1::bar(char) 只在Derived1中，可以直接访问
        bar(c);
        // void bar(int) 在基类Base中，既可以通过D1访问到,也可以通过D2访问到，因此存在二义性,只能限定通过基类名访问
        Base::bar(i);
        // integer的i可以转换为char，因此即使正常调用也是调用的Derived1::bar(char)
        bar(i);
        // foo 在两个基类中都找到匹配的函数，编译器查找名字时发现了二义性，因此都不能直接访问
        Derived2::foo(i);
        Derived1::foo(c);
        // 访问ival成员，由于两个直接基类中只有一个ival，因此优先匹配Derived2中的val，
        cout << ival << " " << Base::ival << endl;
        // 在两个直接基类中都找到了匹配的cval，因此只能通过限定符访问
        cout << Derived1::cval << " " << Derived2::cval << endl;
    }
};


int main() {
    VMI vmi;
    vmi.func();
    return 0;
}

