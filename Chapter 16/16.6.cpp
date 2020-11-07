/**
 * @details : Exercise 16.6 接受数组实参的标准库函数begin和end是如何工作的，定义自己版本的begin和end
 */
#include <iostream>
#include <string>


/**
 * @details 返回数组的首迭代器
 * @param T_ 是类型模板参数
 * @param N_ 是非类型的模板参数
 */
template<typename T_, std::size_t N_>
T_ *Begin(T_ (&arr)[N_]) {
    return arr;
}

/**
 * @details 返回数组的尾后迭代器
 * @param T_ 是类型模板参数
 * @param N_ 是非类型的模板参数
 */
template<typename T_, std::size_t N_>
T_ *End(T_ (&arr)[N_]) {
    return arr + N_;
}

using namespace std;

int main() {

    int arr_int[] = {1, 35, 567, 8, 43, 23, 3};
    string arr_str[] = {"hello", "world", "hello", "today"};
    cout << Begin(arr_int) << " " << End(arr_int) << endl;
    cout << Begin(arr_str) << " " << End(arr_str) << endl;
    return 0;
}

