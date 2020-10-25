/*
 * Exercise 14.34 定义一个函数对象，令其执行if-then-else的操作，
 * 该类的调用运算符接受三个参数，它首先检查第一个形参，如果成功过返回第二个形参的值，不成功则返回第三个形参的值
 */
#include <iostream>
#include <string>


using namespace std;

class If_Then_Else {
public:
    string operator()(bool b, const string &str1, const string &str2) {
        return b ? str1 : str2;
    }
};


int main() {

    auto b = 3 < 2;
    string str1 = "hello";
    string str2 = "world";
    If_Then_Else ife;
    cout << ife(b, str1, str2);
    return 0;
}

