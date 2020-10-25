/*
 * Exercise 13.25 定义StrBlob行为像值的版本，继续使用shared_ptr,
 * 修改后的类需要一个拷贝构造函数和一个拷贝赋值运算符但是不要需要析构函数
 * Exercise 13.26 实现13.25的类
 */
#define Exercise1325

#include <iostream>
#include "../common/header/StrBlob.h"


int main(int argc, char **argv) {
    StrBlob a{"a", "b"}, b;
    std::cout << "对象a内元素:" << std::endl;
    a.print();
    b = a;
    a.push_back("c");
    auto c = a;
    std::cout << "对象a内元素:" << std::endl;
    a.print();
    std::cout << "对象b内元素:" << std::endl;
    b.print();
    std::cout << "对象c内元素:" << std::endl;
    c.print();


    return 0;
}


