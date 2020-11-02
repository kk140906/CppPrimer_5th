/**
 * Exercise 6.54-6.56 编写函数的声明，接受两个int形参，同时返回类型也是int，声明一个vector对象，其元素类型为指向函数的指针
 * 编写4个函数，分别对两个int值执行加、减、乘、除，然后在vector对象中保存这些函数的指针
 * 并输出vector对象中每个元素的结果
 */
#include <iostream>
#include <vector>

using namespace std;

int func(int, int);

int addInteger(int a, int b);

int subInteger(int a, int b);

int multiplyInteger(int a, int b);

int divideInteger(int a, int b);

int main() {
    std::cout << "Hello, World!" << std::endl;
    typedef int FUNC1(int, int);
    typedef int (*PFUNC1)(int, int);
    typedef decltype(func) FUNC2;
    typedef decltype(func) *PFUNC2;
    using FUNC3 = int(int, int);
    using PFUNC3 = int (*)(int, int);
    using FUNC4 = decltype(func);
    using PFUNC4 = decltype(func) *;
    vector<FUNC1 *> vec1 = {addInteger, subInteger, multiplyInteger, divideInteger};
    vector<PFUNC1> vec2 = {addInteger, subInteger, multiplyInteger, divideInteger};
    vector<FUNC2 *> vec3 = {addInteger, subInteger, multiplyInteger, divideInteger};
    vector<PFUNC2> vec4 = {addInteger, subInteger, multiplyInteger, divideInteger};
    vector<FUNC3 *> vec5 = {addInteger, subInteger, multiplyInteger, divideInteger};
    vector<PFUNC3> vec6 = {addInteger, subInteger, multiplyInteger, divideInteger};
    vector<FUNC4 *> vec7 = {addInteger, subInteger, multiplyInteger, divideInteger};
    vector<PFUNC4> vec8 = {addInteger, subInteger, multiplyInteger, divideInteger};
    for (auto i :vec1) {
        cout << "vec1:" << i(5, 2) << endl;
    }
    for (auto i :vec2) {
        cout << "vec2:" << i(5, 2) << endl;
    }
    for (auto i :vec3) {
        cout << "vec3:" << i(5, 2) << endl;
    }
    for (auto i :vec4) {
        cout << "vec4:" << i(5, 2) << endl;
    }
    for (auto i :vec5) {
        cout << "vec5:" << i(5, 2) << endl;
    }
    for (auto i :vec6) {
        cout << "vec6:" << i(5, 2) << endl;
    }
    for (auto i :vec7) {
        cout << "vec7:" << i(5, 2) << endl;
    }
    for (auto i :vec8) {
        cout << "vec8:" << i(5, 2) << endl;
    }
    return 0;
}


int addInteger(int a, int b) {
    return a + b;
}

int subInteger(int a, int b) {
    return a - b;
}

int multiplyInteger(int a, int b) {
    return a * b;
}

int divideInteger(int a, int b) {
    return b != 0 ? a / b : 0;
}
