/**
 * @details : Exercise 16.45
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>

using namespace std;

template<typename T>
void g(T &&val) { vector<T> v; }

int main() {
    // 42是一个右值，推断的T的类型就是int,函数体内部相当于创建了一个存放int类型的vector
    g(42);
    int i = 42;
    // 如果采用int类型变量作为函数的实参，推断的T的类型就是int &,
    // 那么函数体内部的定义相当于创建一个存放int &的vector,
    // 但是引用不是对象，不能创建内存实体，因此会认为错误
//    g(i);
    return 0;
}

