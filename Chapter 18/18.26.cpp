/**
 * @details: Exercise 18.26 有如下的继承体系，下面对print的调用为什么是错误的，适当修改MI，令其对print的调用可以编译通过并正确执行
 * @details: Exercise 18.27 有如下的继承体系，同时假定为MI添加一个名为foo的函数
 *                          int ival;
 *                          double dval;
 *                          void MI::foo(double cval){
 *                              int dval;
 *                              // 练习的问题
 *                              // (a) 列出MI::foo中可见的所有名字
 *                              // (b) 是否存在某个可见的名字是继承自多个基类
 *                              // (c) 将Base1中的dval成员与Derived的dval成员求和后赋值给dval的局部实例
 *                              // (d) 将MI::dvec的最后一个元素赋值给Base2::fval;
 *                              // (e) 将Base1继承的cval赋给从Derived继承的sval的第一个字符
 *                          }
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Base1 {
    void print(int) const { cout << __PRETTY_FUNCTION__ << endl; }

protected:
    int ival;
    double dval;
    char cval;
private:
    int *id;
};

struct Base2 {
    void print(double) const { cout << __PRETTY_FUNCTION__ << endl; }

protected:
    double fval;
private:
    double dval;
};

struct Derived : public Base1 {
    void print(const std::string) const { cout << __PRETTY_FUNCTION__ << endl; }

protected:
    std::string sval;
    double dval;
};


struct MI : public Derived, public Base2 {
    void print(std::vector<double>) { cout << __PRETTY_FUNCTION__ << endl; }
    // 不能访问的原因是在基类Base1和基类Base2中都找到了可行的匹配函数，尽管两个函数的形参不一致，
    // 但是名字的查找优先于类型检查，因此找到两个可行的名字时编译器就已经提示错误了，
    // 为了避免多继承下的派生类的二义性问题，最好的方式就是在派生类中重写需要的函数，这里可以直接通过using声明替换函数重定义
    using Base1::print;
    using Base2::print;

    void foo(double);

protected:
    int *ival;
    std::vector<double> dvec;
};


int ival;
double dval;

void MI::foo(double cval) {
    int dval;
    // a-e
    // (a) foo中可见的成员名字为:
    // foo::dval; foo::cval; MI::ival; MI::dvec; MI::print; Derived::sval; Base2::fval
    // (b) dval和print虽然继承自多个基类，但是由于函数定义的局部dval实际已经覆盖了基类的dval
    // (c)
    dval = Base1::dval + Derived::dval;
    // (d)
    fval = dvec.back();
    // (e)
    sval[0]= Base1::cval;
}

int main() {
    MI mi;
    mi.print(42);
    return 0;
}

