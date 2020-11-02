/**
 * Exercise 10.28 一个vector中保存1到9,分别使用inserter,back_inserter,front_inserter将其拷贝到三个容器中
 * */
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int main(int argc, char **argv) {
    vector<int> v_int{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l_int1, l_int2, l_int3;
    cout << "list1:" << endl;
    copy(v_int.cbegin(), v_int.cend(), inserter(l_int1, l_int1.begin()));
    for_each(l_int1.cbegin(), l_int1.cend(), [](const int &i) { cout << i << " "; });
    cout << endl;
    cout << "list2:" << endl;
    copy(v_int.cbegin(), v_int.cend(), back_inserter(l_int2));
    for_each(l_int2.cbegin(), l_int2.cend(), [](const int &i) { cout << i << " "; });
    cout << endl;
    cout << "list3:" << endl;
    copy(v_int.cbegin(), v_int.cend(), front_inserter(l_int3));
    for_each(l_int3.cbegin(), l_int3.cend(), [](const int &i) { cout << i << " "; });
    cout << endl;
    return 0;
}


