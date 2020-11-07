/**
 * @details : Exercise 16.7 编写一个constexpr的模板，返回给定数组的大小
 */
#include <iostream>
#include <string>


/**
 * @details 返回数组的大小
 * @param T_ 是类型模板参数
 * @param N_ 是非类型的模板参数
 */
template<typename T_, std::size_t N_>
constexpr std::size_t Size(const T_ (&arr)[N_]) {
    return N_;
}

using namespace std;

int main() {

    int arr_int[] = {1, 35, 567, 8, 43, 23, 3};
    string arr_str[] = {"hello", "world", "hello", "today"};
    cout << "size: " << Size(arr_int) << endl << "size: " << Size(arr_str) << endl;
    return 0;
}

