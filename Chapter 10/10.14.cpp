/*
 * Exercise 10.14 编写一个lambda，接受两个int，返回他们的和
 * */
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int a = 3, b = 7;
    auto sumInt = [](int &a, int &b) {
        return a + b;
    };
    cout << sumInt(a, b) << endl;
    return 0;
}


