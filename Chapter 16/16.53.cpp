/**
 * @details : Exercise 16.53 编写自己版本的print函数，并打印一个、两个、及五个实参来测试它，要求打印的每个实参应该都有不同的类型
 * @details : Exercise 16.54 如果我们对一个没有定义<<运算符的类型调用print会发生什么
 * @details : Exercise 16.55 如果在可变参数版本之后再定义非可变参数的版本，会发生什么
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>

using namespace std;

// 非可变参数的函数模板，保证递归终止的条件，如果在定义可变参数版本之后再申明该版本则可变参数版本将不会正常结束递归调用
// 在结束递归的时候，两个模板都可以生成适用的函数实例，
// 但是由于该函数模板是非可变参数的模板，更加特例化，而编译器通常会优先选择更加特例化的版本，因此该版本可以正常结束递归调用
template<typename T_>
ostream &print(ostream &os, const T_ &rhs) {
    return os << rhs;
}

// 可变参数版本
template<typename T_, typename... Args>
ostream &print(ostream &os, const T_ &rhs, const Args &... args) {
    os << rhs << ",";
    // 函数参数包扩展
    return print(os, args...);
}

struct A {
};

int main() {
    int i = 42;
    float f = 3.3;
    char c = 'g';
    double d = 3.14;
    string s = "hello";
    cout << "------------print 1 argument---------" << endl;
    print(cout, i);
    cout << endl;
    cout << "------------print 2 argument---------" << endl;
    print(cout, d, c);
    cout << endl;
    cout << "------------print 6 argument---------" << endl;
    print(cout, i, f, c, d, s, 66);
    cout << endl;
    // 未定义<<运算符将会编译出错
//    A a;
//    print(cout ,a);
    return 0;
}

