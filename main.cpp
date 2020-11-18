
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <regex>
#include <windows.h>

namespace A {
    void print() {}

    void print(const std::string &) {}
}
namespace B {
    void print(int) {}

    void print(double) {}
}

void print(int) {}

using A::print;
using namespace B;

int main() {
    print(); // A::print()
    print("hello"); // A::print(const std::string &)
    print(3.14); // B::print(double)
    B::print(5); // B::print(int)
    ::print(10); // ::print(int)
    return 0;
}

