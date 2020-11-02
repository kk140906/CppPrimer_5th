/**
 * Exercise 6.21 编写一个函数，令其接受两个参数，一个int类型，一个是int * 类型，函数比较int类型和int * 所指的值，返回较大的那个
 */
#include <iostream>

using namespace std;

/*
 * num1 使用const限定表明在函数体内部不需要更改
 * num2_ptr 使用const限定表面在函数体内部不会更改其指向的值
 */
int findMaxNum(const int num1, const int *num2_ptr);

int main() {
    std::cout << "Hello, World!" << std::endl;
    int num1 = 20, num2 = 40;
    int *num2_ptr = &num2;
    cout << findMaxNum(num1, num2_ptr) << endl;
    return 0;
}

int findMaxNum(const int num1, const int *num2_ptr) {
    return num1 > *num2_ptr ? num1 : *num2_ptr;
}
