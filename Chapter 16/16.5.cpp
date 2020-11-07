/**
 * Exercise 16.5 为P195页的print函数编写模板版本，它接受一个数组的引用，能处理任意大小，任意元素类型的数组
 */
#include <iostream>
#include <string>


/**
 * @param T_ 是类型模板参数
 * @param N_ 是非类型的模板参数
 */
template<typename T_, std::size_t N_>
void Print(const T_ (&arr)[N_]) {
    for (const auto &ca : arr) {
        std::cout << ca << " ";
    }
    std::cout << std::endl;
}


using namespace std;

int main() {

    int arr_int[] = {1, 35, 567, 8, 43, 23, 3};
    string arr_str[] = {"hello", "world"};
    // Print函数模板接受两个模板参数，均可以通过实参进行推导
    // 第二个模板参数为非类型的模板参数，编译器要求根据实参推导出来的值必须是常量表达式
    Print(arr_int);
    Print(arr_str);
    return 0;
}

