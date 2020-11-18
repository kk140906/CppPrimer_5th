/**
 * @details : Exercise 16.56 编写并测试可变参数版本的errorMsg
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <sstream>
#include <cassert>

#define NDEBUG

using namespace std;

template<typename T_>
string debug_rep(const T_ &arg);

template<typename T_>
string debug_rep(T_ *arg);

string debug_rep(const string &arg);

string debug_rep(char *arg);

string debug_rep(const char *arg);

void Debug();


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

template<typename... Args>
ostream &errorMsg(ostream &os, const Args &...args) {
    // 注意debug_rep并没有可变参数版本的定义，扩展操作只能针对errorMsg进行
    return print(os, debug_rep(args)...);
}

int main() {

    int i = 42;
    float j = 3.2;
    double d = 4.5;
    char c = 'g';
    string s = "hello";
    const int ci = 55;
    const int *const pi = &i;
    const int *const &rpi = &i;
    errorMsg(cout, i, j, d, c, s, ci, pi, rpi);
    return 0;
}

void Debug() {
#ifndef NDEBUG
    cout << __PRETTY_FUNCTION__ << endl;
#endif
}

template<typename T_>
string debug_rep(const T_ &arg) {
    Debug();
    ostringstream ret;
    ret << arg;
    return ret.str();
}

template<typename T_>
string debug_rep(T_ *arg) {
    Debug();
    ostringstream ret;
    ret << "Pointer address: " << arg << ",";
    if (arg) {
        ret << "Value: " << debug_rep(*arg);
    } else {
        ret << "nullptr";
    }
    return ret.str();
}


string debug_rep(const string &arg) {
    Debug();
    return '"' + arg + '"';
}

string debug_rep(char *arg) {
    Debug();
    return debug_rep(string(arg));
}

string debug_rep(const char *arg) {
    Debug();
    return debug_rep(string(arg));
}