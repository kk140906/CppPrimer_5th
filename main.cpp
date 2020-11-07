
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>

using namespace std;

template<typename T>
bool compare(const T &lhs, const T &rhs) {
    cout << __PRETTY_FUNCTION__ << endl;
    return false;
}

//template<>
//bool compare(char *const &lhs, char *const &rhs) {
//    cout << "hello:" << __PRETTY_FUNCTION__ << endl;
//
//    return true;
//}


int main(int argc, char **argv) {
    int i = 42;
    const char *c1 = "hello";
    const char *c2 = "kk";
    compare(c1, c2);
    return 0;
}


