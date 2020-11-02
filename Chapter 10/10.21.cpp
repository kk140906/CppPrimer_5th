/**
 * Exercise 10.21 编写一个lambda，捕获一个局部int变量，并递减变量值，直至它变为0，一旦变量变为0，再调用lambda应该不再递减变量，、
 * lambda返回一个bool值，指出捕获的变量是否为0
 * */
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int i = 5;
    // mutable表明捕获的变量是可被更改的,捕获变量采用的是值捕获，不会更改原来i的值，如果是引用捕获则会更改i的值
    auto f = [i]() mutable -> bool {
        cout << "start: " << i << endl;
        while (i) {
            cout << "i = " << i << endl;
            --i;
        }
        cout << "end: " << i << endl;
        return true;
    };
    // 由于捕获的变量是在lambda创建时就被拷贝到lambda内部，而不是在调用时拷贝的，
    // 因此当第一次调用f()后，捕获的变量i已经递减为0，第二次调用f()时由于不会再重新拷贝捕获变量i的值，而是保留之前递减之后的i的值
    // 这有点类似于lambda内部的静态局部变量
    cout << "调用前 i = " << i << endl;
    f();
    cout << "第一次调用后 i = " << i << endl;
    f();
    cout << "第二次调用后 i = " << i << endl;
    return 0;
}


