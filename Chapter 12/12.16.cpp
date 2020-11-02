/**
 *  Exercise 12.16 如果试图拷贝或赋值unique_ptr,编译器并不总是给出易于理解得错误信息
 *  编写包含这些错误的程序，观察编译器如何诊断这些错误
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(int argc, char **argv) {

    unique_ptr<string> p_str1(new string("string"));
    unique_ptr<string> p_str2;
    // error: no match for 'operator='
//    p_str2 = new string();
    p_str2.reset();
    // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&)
//    p_str2 = p_str1;
    // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&)
//    unique_ptr<string> p_str3(p_str1);

    return 0;
}


