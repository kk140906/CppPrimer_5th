/**
 * @details : Exercise 16.34
 * @details : Exercise 16.35
 * @details : Exercise 16.36
 */

#include <iostream>
#include <string>
#include <vector>


using namespace std;

template<typename T>
int compare(const T &, const T &) { return 0; }


template<typename T>
T calc(T, int) { return T(); }

template<typename T>
T fcn(T, T) { return T(); }


template<typename T>
void f1(T, T) {}

template<typename T1, typename T2>
void f2(T1, T2) {}


int main() {
    // "hi"与"world”底层本质上可以看做字符数组，hi:const char[3],world:const char[6]
    // 做实参类型推断的时候会认为是不同的类型，compare的两个形参使用了相同的模板形参
    // 而对于形参类型为引用类型的数组不会发生类型转换
//    compare("hi", "world");
    // 两者推断的结果都是const char[4]
    compare("bye", "daa");

    double d;
    float f;
    char c;
    // char calc(char,int)
    calc(c, 'c');
    // double calc(double,int)
    calc(d, f);
    // char fcn(char,char)
    fcn(c, 'c');
    // fcn 接受两个同类型的实参，而d是double类型,f是float类型
//    fcn(d,f)

    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = &i, *cp2 = &j;
    // f1(int*, int*)
    f1(p1, p2);
    // f2(int*, int*)
    f2(p1, p2);
    // f1(const int*,const int*)
    f1(cp1, cp2);
    // f2(const int*, const int*)
    f2(cp1, cp2);
    // f1要求模板实参类型必须相同，而p1是普通的int*,cp1是const int*，类型不同
    // 编译器不会进行类型转换，而是根据模板实参直接生成新的模板实例，f1的两个实参类型不同，无法正确生成实例
//    f1(p1, cp1);
    // f2(int* const int*) const转换
    f2(p1, cp1);


    return 0;
}

