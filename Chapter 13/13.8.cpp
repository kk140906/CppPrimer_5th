/**
 * Exercise 13.8 给下面的类框架，编写一个拷贝赋值运算符，类似于Exercise 13.5的拷贝构造函数，赋值运算符应该将对象拷贝到ps指向的位置
 * 你的构造函数应该动态分配一个新string，并将对象拷贝到ps指向的位置，而不是拷贝ps本身
 * class HasPtr{
 * public:
 *      HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
 * private:
 *      std::string *ps;
 *      int i;
 * };
 * */
#include <iostream>
#include <string>

using namespace std;

class HasPtr {

public:
    HasPtr(const std::string &s = std::string(), const int ii = 0) : ps(new std::string(s)), i(ii) {}

    // 拷贝构造函数,赋值初始化
    HasPtr(const HasPtr &obj) : ps(new std::string(*obj.ps)), i(obj.i) { std::cout << "调用拷贝构造函数" << std::endl; }

    // 拷贝赋值运算符
    HasPtr &operator=(const HasPtr &right) {
        std::cout << "调用拷贝赋值运算符" << std::endl;
        auto newPs = new std::string(*right.ps);
        delete ps;
        ps = newPs;
        i = right.i;
        return *this;
    }

    void print() {
        std::cout << *ps << std::endl;
        std::cout << i << std::endl;
    }

private:
    std::string *ps;
    int i;
};

int main(int argc, char **argv) {
    HasPtr p1("hello", 10), p2;
    p2.print();
    // 调用拷贝赋值运算符
    p2 = p1;
    p2.print();
    // 调用拷贝构造函数，注意与拷贝赋值运算符区分
    // 在对象定义时的 ”=“ 是调用拷贝构造函数,不是调用拷贝赋值运算符
    HasPtr p3 = p1;
    p3.print();
    return 0;
}


