/**
 * Exercise 9.50 编写程序处理一个vector<string>,里面元素都是int类型数值或者double类型数值，计算vector中所有元素之和
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char **argv) {
    vector<string> v_int_str{"1", "4", "5", "-7"};
    vector<string> v_double_str{"1.6", "-5.1", "5", "-7.2"};
    int sum_int = 0;
    for (const auto &s : v_int_str) {
        sum_int += stoi(s);
    }
    cout << sum_int << endl;
    double sum_double = 0;
    for (const auto &s : v_double_str) {
        sum_double += stod(s);
    }
    cout << sum_double << endl;
    return 0;
}


