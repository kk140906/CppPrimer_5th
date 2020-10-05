/*
 * Exercise 10.1-10.2 头文件algorithm中定义了一个count函数，接受一个迭代器和一个值作为参数，
 * count返回在给定序列中出现的次数，编写程序读取int序列存入vector中，打印有多少个元素的值是count给定的值
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


int main(int argc, char **argv) {
    vector<int> v_int{1, 3, 4, 5, 2, 5, 6, 2, 3, 4};
    cout << "3出现的次数:" << count(v_int.cbegin(), v_int.cend(), 3) << endl;
    list<string> l_str{"h", "hello", "world", "h", "hello"};
    cout << "h字符串出现的次数:" << count(l_str.cbegin(), l_str.cend(), "h");
    return 0;
}


