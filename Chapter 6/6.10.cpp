/**
 * Exercise 6.10 编写一段程序,交换两个实参的值
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swapValueByPointer(int *num1, int *num2);

void swapValueByReference(int &num1, int &num2);

int main() {
    std::cout << "Hello, World!" << std::endl;
    int num1 = 30, num2 = 50;
    cout << "交换前，" << "num1 = " << num1 << "," << "num2 = " << num2 << endl;
    swapValueByPointer(&num1, &num2);
    cout << "通过指针形参交换后，" << "num1 = " << num1 << "," << "num2 = " << num2 << endl;
    swapValueByReference(num1, num2);
    cout << "通过引用形参交换后，" << "num1 = " << num1 << "," << "num2 = " << num2 << endl;
    return 0;
}

void swapValueByPointer(int *num1, int *num2) {
    auto tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void swapValueByReference(int &num1, int &num2) {
    auto tmp = num1;
    num1 = num2;
    num2 = tmp;
}
