/**
 * @details : Exercise 16.49
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>


using namespace std;

template<typename T_>
void f(T_) {
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T_>
void f(const T_ *) {
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T_>
void g(T_) {
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T_>
void g(T_ *) {
    cout << __PRETTY_FUNCTION__ << endl;
}

int main() {

    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    // 调用g(T_),T_的类型为int,函数形参类为int
    g(42);
    // 调用g(T_ *),T_的类型为int,函数形参类为int *。
    // 该调用两个模板都能匹配，第一个模板T_的类型为int *,第二个模板T_的类型为int
    // 由于第二个模板更加特例化，编译器会优先选择第二个版本
    g(p);
    // 调用g(T_),T_的类型为int,函数形参类为int,拷贝初始化时会忽略const.
    g(ci);
    // 调用g(T_ *),T_的类型为const int,函数形参类为const int *,const是底层const，不能被忽略
    // 该调用两个模板都能匹配,第一个模板 T_类型为const int *,T_的类型为const int
    // 但是第二个模板更加特例化，编译器会优先选择第二个版本
    g(p2);

    cout << endl;

    // 调用f(T_),T_的类型为int,函数形参类为int
    f(42);
    // 调用f(T_),T_的类型为int *,函数形参类为int *，
    // 该调用两个模板都能匹配，第一个模板T_的类型为int *,推断的函数为void f(int *);
    // 第二个模板T_的类型为int,推断的函数类型为void f(const int *)
    // 第二个模板相对于第一个模板有一个普通指针向const指针的转换，因此第一模板会被调用
    f(p);
    // 调用f(T_),T_的类型为int,函数形参类为int,拷贝初始化时会忽略const
    f(ci);
    // 调用f(const T_ *),T_的类型为int,函数形参类为const int *,const是底层const，不能被忽略
    // 该调用两个模板都能匹配，第一个模板T_类型为const int *,第二个模板T_的类型为int
    // 由于第二个模板更加特例化，编译器会优先选用第二个版本
    f(p2);
    cout << endl;

    return 0;
}

