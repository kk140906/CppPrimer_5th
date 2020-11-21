/**
 * @details: Exercise 18.30 在Base中定义一个默认构造函数，一个拷贝构造函数，和一个接受int类型的构造函数
 *                          在每个派生类中分别定义这三种构造函数，每个构造函数应该使用它的实参初始化其Base部分
 */
#include <iostream>
#include <string>

using namespace std;

struct Base {
    Base() : val(0) {};

    Base(int i) : val(i) {}

    Base(const Base &rhs) : val(rhs.val) {}

private:
    int val;
};

struct Derived : public Base {
    Derived() : Base(0) {}

    Derived(int i) : Base(i) {}

    Derived(const Derived &rhs) : Base(rhs) {}
};

int main() {
    return 0;
}

