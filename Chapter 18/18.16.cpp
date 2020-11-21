/**
 * @details: Exercise 18.16 假设在下面代码中，位置1的地方对于Exercise中所有成员使用using声明会发生什么，
 *           如果位置2的地方使用using声明又会发生什么，如果using声明替换为using指示又会怎样。
 * @details: Exercise 18.17 验证18.16的练习结果
 */
#include <iostream>
#include <string>
#include "../common/header/Sales_data.h"

using namespace std;

namespace Exercise{
    int i_var = 0;
    double d_var = 0;
    const int limit = 1000;
}

int i_var = 0;
// 位置1
// using声明后与全局作用域中i_var出现重复定义
//using Exercise::i_var;
using Exercise::d_var;
using Exercise::limit;

// using namespace Exercise;

int main() {
    // 位置2
    // using声明后局部变量隐藏了全局变量
    using Exercise::i_var;
    // using声明后与局部作用域中d_var出现重复定义
//    using Exercise::d_var;
    using Exercise::limit;
    // using namespace Exercise;
    double d_var = 3.14156;
    int i_obj = limit + 1;
    ++i_var;
    ++::i_var;
}

