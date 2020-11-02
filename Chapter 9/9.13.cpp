/**
 * Exercise 9.13 验证使用存储int元素的list容器初始化存储double元素的vector容器会发生什么情况?
 * 如果利用存储int的vector容器初始化存储double元素的容器又会发生什么情况?
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;


int main(int argc, char **argv) {
    list<int> l_int{1, 2, 3, 4, 5};
    // 由于容器的类型不同不能直接进行容器的拷贝初始化
//    vector<double> v_double(l_int);
    // 通过迭代器实现,int可以转换为double
    vector<double> v_double(l_int.cbegin(), l_int.cend());
    for (const auto &vd : v_double) {
        cout << vd << endl;
    }
    vector<int> v_int{1, 2, 3, 4, 5};
    // 同样的，容器内元素类型不一致也不能直接拷贝初始化
//    vector<double> v_double2(v_int);
    // 使用迭代器范围进行初始化
    vector<double> v_double2(v_int.cbegin(), v_int.cend());
    for (const auto &vd : v_double2) {
        cout << vd << endl;
    }
    return 0;
}


