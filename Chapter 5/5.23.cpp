/*
 * Exercise 5.24 编写一段程序，从标准输入中读取两个整数，输出第一个数除以第二个数的结果，同时使得第二个数是0时抛出异常，然后设定
 * catch子句，捕获异常
 * 发现一个疑问的地方，当进行5.25测试时，当被除数是0时，如果输入N语句块内不抛异常而使用break，那么函数返回的结果是1
 * 初步猜测：函数名实际是一个指针，根据函数返回值类型决定指针所指向的类型，如果未指定返回值，那么返回值应是对应内存地址所存储的随机值
 */

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

int exercise_5_24();

int exercise_5_25();

int main() {
    cout << "请输入需要测试的练习题号：1-5.24 2-5.25" << endl;
    int exerciseNum;
    cin >> exerciseNum;
    decltype(exercise_5_24()) result;
    if (1 == exerciseNum) {
        result = exercise_5_24();
        cout << "测试结果为：" << result;
    } else if (2 == exerciseNum) {
        result = exercise_5_25();
        cout << "测试结果为：" << result;
    }
    return 0;
}

int exercise_5_24() {
    cout << "请输入两个整数:" << endl;
    int num1, num2;
    cin >> num1 >> num2;
    if (0 == num2) {
        throw std::invalid_argument("被除数为0！");
    } else {
        return num1 / num2;
    }
}

int exercise_5_25() {
    while (true) {
        try {
            cout << "请输入两个整数:" << endl;
            int num1, num2;
            cin >> num1 >> num2;
            if (0 == num2) {
                throw std::invalid_argument("被除数为0！请确认是否重新输入新的值，Y or N?");
            } else {
                return num1 / num2;
            }
        } catch (std::invalid_argument argError) {
            cout << argError.what() << endl;
            char confirm;
            cin >> confirm;
            if ('Y' == confirm) {
                continue;
            } else if ('N' == confirm) {
                throw std::invalid_argument("被除数为0,exit!");
//                break;
            }
        }
    }
}
