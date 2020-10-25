/*
 * Exercise 13.55 为你的StrBlob类添加一个右值引用版本的push_back;
 * */

#include "../common/header/StrBlob.h"

using namespace std;

int main(int argc, char **argv) {

    StrBlob a{"a", "b"}, b;
    std::cout << "对象a内元素:" << std::endl;
    a.print();
    b = a;
    // 这会调用右值引用版本的push_back
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



