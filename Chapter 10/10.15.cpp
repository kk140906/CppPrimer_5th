/*
 * Exercise 10.15 编写一个lambda，接受一个int，捕获函数内部的int，返回他们的和
 * */
#include <iostream>

using namespace std;

void sumInt() {
    int a = 3;
    auto f = [a](int b) -> int {
        return a + b;
    };
    cout << f(3) << endl;
}

int main(int argc, char **argv) {
    sumInt();
    return 0;
}


