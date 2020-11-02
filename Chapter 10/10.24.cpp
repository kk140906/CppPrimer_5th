/**
 * Exercise 10.24 给定一个string，使用bind和check_size在一个int的vector中查找第一个大鱼string长度的值
 * */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string::size_type check_size(const string &str, const string::size_type size) {
    return str.size() < size;
}

int main(int argc, char **argv) {
    vector<int> v_int{1, 1, 3, 2, 0, 4, 5, 2, 3, 7, 5, 3, 6};
    string str = "hello";
    cout << "string长度为:" << str.size() << "\n容器中第一个大于string长度的数值为:\n"
         << *find_if(v_int.cbegin(), v_int.cend(), bind(check_size, str, placeholders::_1)) << endl;
    return 0;
}


