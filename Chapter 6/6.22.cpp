/**
 * Exercise 6.22 编写一个函数，交换两个int类型的指针,实际交换两个int类型指针的所存储的值，等价于交换两个指针互相指向的对象。
 */
#include <iostream>

using namespace std;

/*
 * ptr1 使用const限定表面在函数体内部不会更改其指向的值
 * ptr2 使用const限定表面在函数体内部不会更改其指向的值
 */
void swapPointer(const int **ptr1, const int **ptr2);

int main() {
    std::cout << "Hello, World!" << std::endl;
    const int num1 = 20, num2 = 40;
    const int *ptr1 = &num1, *ptr2 = &num2;
    cout << "交换前: ptr1指向" << *ptr1 << "," << "ptr2指向" << *ptr2 << endl;
    swapPointer(&ptr1, &ptr2);
    cout << "交换后: ptr1指向" << *ptr1 << "," << "ptr2指向" << *ptr2 << endl;
    return 0;
}

void swapPointer(const int **ptr1, const int **ptr2) {
    auto tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}
