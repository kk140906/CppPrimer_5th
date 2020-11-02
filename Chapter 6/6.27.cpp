/**
 * Exercise 6.27 编写一个函数，它的参数是 initializer_list<int>类型的对象，函数的功能是计拌列表中所有元素的和。
 */
#include <iostream>
#include <initializer_list>

using namespace std;

int toSum(initializer_list<int> il);

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << toSum({1, 2, 3, 5}) << endl;
    return 0;
}

int toSum(initializer_list<int> il) {
    int sum = 0;
    // 声明为对常量的引用，避免拷贝操作
    for (const auto &item : il) {
        sum += item;
    }
    return sum;
}

