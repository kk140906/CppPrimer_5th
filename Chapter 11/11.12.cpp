/*
 * Exercise 11.12 编写程序，读入string和int的序列,将每个string和int存入一个pair，pair保存在一个vector中
 * Exercise 11.13 至少采用三种方式创建pair的方法
 * */
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <utility>

using namespace std;


int main(int argc, char **argv) {
    vector<string> v_str{"hello", "word", "today"};
    vector<int> v_int{1, 3, 5};
    vector<pair<string, int>> vp_str_int;
    for (auto cnt = 0; cnt < (v_str.size() > v_int.size() ? v_int.size() : v_str.size()); ++cnt) {
        // 直接列表初始化
        vp_str_int.emplace_back(v_str[cnt], v_int[cnt]);
        // 创建pair对象
        vp_str_int.emplace_back(v_str[cnt], v_int[cnt]);
        // 利用make_pair函数
        vp_str_int.emplace_back(v_str[cnt], v_int[cnt]);
    }
    for (const auto &vp : vp_str_int) {
        cout << "pair: " << vp.first << " , " << vp.second << endl;
    }
    return 0;
}


