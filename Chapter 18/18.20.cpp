/**
 * @details: Exercise 18.20 以下代码中，确定哪个函数与compute调用匹配,如果将using声明置于f中compute调用之前会怎样?
 */
#include <iostream>

#ifndef NDEBUG
#define PRINT_FUNCTION  std::cout <<  __PRETTY_FUNCTION__ << std::endl
#endif

namespace primerLib {
    void compute() { PRINT_FUNCTION; }

    void compute(const void *) { PRINT_FUNCTION; }
}

using primerLib::compute;

void compute(int) { PRINT_FUNCTION; }

void compute(double, double = 3.14) { PRINT_FUNCTION; }

void compute(char *, char * = nullptr) { PRINT_FUNCTION; }

void f() {
//    using primerLib::compute;
    compute(0);
}

int main() {
    /**
     * 当using声明位于全局作用域时，compute的可行函数有：
     * void primerLib::compute(const void *); // int转const void *,指针转换匹配一样好
     * void compute(int); // 精确匹配
     * void compute(double,double = 3.14); // int转double,第二匹配
     * void computer(char *,char * = nullptr); // int转char *，指针转换匹配一样好
     * 当using声明位于函数局部作用域时，会隐藏外部的所有同名的函数，compute的可行函数只有：
     * void primerLib::compute(const void *); // int转const void *
     */
    f();
}

