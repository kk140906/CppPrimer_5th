/*
 * Exercise 10.3-10.4 用accumulate求一个vector<int>的值，
 * 如果容器v类型是vector<double>,调用accumulate(v.cbegin(),v.cend(),0)会损失计算精度,因为返回值是整型
 * */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main(int argc, char **argv) {
    vector<int> v_int{1, 3, 4, 5, 2, 5, 6, 2, 3, 4};
    cout << accumulate(v_int.cbegin(), v_int.cend(), 0) << endl;
    vector<double> v_double{0.1, 0.2, 0.5, 1.105};
    cout << accumulate(v_double.cbegin(), v_double.cend(), 0) << endl;
    return 0;
}


