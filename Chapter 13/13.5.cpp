/**
 * Exercise 13.5 给下面的类框架，编写一个拷贝构造函数，拷贝所有成员，
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

    // 赋值初始化
    HasPtr(const HasPtr &obj) : ps(new std::string(*obj.ps)), i(obj.i) { std::cout << "调用拷贝构造函数" << std::endl; }

    void print() {
        cout << *ps << endl;
        cout << i << endl;
    }

private:
    std::string *ps;
    int i;
};

int main(int argc, char **argv) {
    // p1 直接初始化，p2拷贝初始化
    HasPtr p1("hello", 3), p2(p1);
    // p3拷贝初始化
    HasPtr p3 = p1;
    p1.print();
    p2.print();
    p3.print();
    return 0;
}


