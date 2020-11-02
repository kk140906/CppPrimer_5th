/**
 * Exercise 9.15 判断两个vector<int>，或者vector<string>的大小
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char **argv) {
    vector<string> v_str1, v_str2;
    v_str1 = {"hello", "world"};
    v_str2 = {"hello"};
    // 如果两个容器的元素及类型不完全相等，那么容器比较大小的结果实际是比较的是两个容器第一个不同元素的大小结果
    vector<int> v_int1{1, 5, 9, 20}, v_int2{1, 20, 5, 20};
    if (v_str1 >= v_str2) {
        cout << "v_str1 >= v_str2" << endl;
    } else {
        cout << "v_str1 < v_str2" << endl;
    }

    if (v_int1 >= v_int2) {
        cout << "v_int1 >= v_int2" << endl;
    } else {
        cout << "v_int1 < v_int2" << endl;
    }
    return 0;
}


