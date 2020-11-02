/**
 * Exercise 14.44 编写一个简单的桌面计算机器，使其能够处理二元计算
 */


#include <unordered_map>
#include <functional>
#include <string>
#include <iostream>

auto modulus = [](const int &lhs, const int &rhs) { return lhs % rhs; };

struct Divide {
    int operator()(const int &lhs, const int &rhs) {
        return lhs / rhs;
    }
};

class Calculator {
    using op_type = std::string;
    using op_func = std::function<int(int, int)>;
public:
    int operator()(op_type t, int lhs, int rhs) {
        return funcTable[t](lhs, rhs);
    }

private:
    std::unordered_map<op_type, op_func> funcTable = {
            {"+", add}, // 函数指针形式
            {"-", std::minus<int>()}, // 标准库函数对象形式
            {"*", [](const auto &lhs, const auto &rhs) { return lhs * rhs; }}, // 未命名的lambda表达式形式
            {"/", Divide()}, // 自定义的函数对象形式
            {"%", modulus} // 命名的lambda表达式形式
    };

    // 类的成员函数的第一个参数是隐含的this指针，导致调用形式与声明的function<int(int,int)>中的调用形式不匹配。
    // 声明为静态可以覆盖掉this指针
    static int add(int lhs, int rhs) { return lhs + rhs; }


};

using namespace std;

int main() {
    Calculator cal;
    cout << cal("+", 1, 2) << " "
         << cal("-", 3, 5) << " "
         << cal("*", 2, 4) << " "
         << cal("/", 8, 3) << " "
         << cal("%", 5, 7);
    return 0;
}

