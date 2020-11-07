/**
 * @details : Exercise 16.42
 * @details : Exercise 16.43
 * @details : Exercise 16.44
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>

using namespace std;

template<typename T>
void g(T &&val) { T t = val; }


template<typename T>
void g1(T val) { T t = val; }

template<typename T>
void g2(const T &val) { T t = val; }

int main() {
    int i = 0;
    const int ci = i;
    // i为左值，T的类型为int &，val的类型为int &
    g(i);
    // ci为左值，T的类型为const int &，val的类型为const int &
    g(ci);
    // i*ci为右值，T的类型为int，val的类型为int &&
    g(i * ci);
    // i = ci的值为i，是个左值，T的类型为int &,val的类型为int &
    g(i = ci);

    // i为左值，T的类型为int，val的类型为int
    g1(i);
    // ci为左值，T的类型为int，val的类型为int
    g1(ci);
    // i*ci为右值，T的类型为int，val的类型为int
    g1(i * ci);
    // i = ci的值为i，是个左值，T的类型为int,val的类型为int
    g1(i = ci);


    // i为左值，T的类型为int，val的类型为const int &
    g2(i);
    // ci为左值，T的类型为int，val的类型为const int &
    g2(ci);
    // i*ci为右值，T的类型为int，val的类型为cont int &
    g2(i * ci);
    // i = ci的值为i，是个左值，T的类型为int,val的类型为const int &
    g2(i = ci);
    return 0;
}

