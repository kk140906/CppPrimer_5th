
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <regex>
#include <windows.h>

struct A {
    void fun() { std::cout << "A" << std::endl; }
};

struct B : public A {

};

int main() {

    B b,*pb;
    A *pa;


    return 0;
}

