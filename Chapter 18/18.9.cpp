/**
 * @details: Exercise 18.9 定义一个书店程序的异常类，然后为Sales_data类重新编写一个复合赋值运算符并令其抛出一个异常
 * @details: Exercise 18.10 编写程序令其对两个ISBN编号不同的对象执行Sales_data加法操作，
 *           编写两个版本的程序，一个处理异常，一个不处理异常
 */
#include <iostream>
#include <string>
#include "../common/header/Sales_data.h"

class out_of_stock : public std::runtime_error {
public:
    explicit out_of_stock(const char *s) : std::runtime_error(s) {};
};

using namespace std;

int main() {
    Sales_data sd1("123456789"), sd2("112233445566778899");
    try {
        Sales_data sd3 = sd1 + sd2;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
    Sales_data sd3 = sd1 + sd2;
}

