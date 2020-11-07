/**
 * Exercise 16.4 编写行为类似标准库find算法的模板，函数需要两个模板类型参数
 * 一个表示函数的迭代器参数，另一个表示值的类型，使用该函数在vector<int>和一个list<string>中查找给定的值
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>


template<typename Ti_, typename Tv_>
Ti_ Find(Ti_ first, Ti_ last, const Tv_ &value) {
    return std::find(first, last, value);
}

using namespace std;

int main() {

    vector<int> vi{1, 2, 4, 6, 7, 3, 4, 5, 8, 9};
    list<string> ls{"hello", "world", "hello", "today"};

    int i = 3;
    auto vi_last = Find(vi.begin(), vi.end(), i);
    if (vi.end() == vi_last) {
        cout << "Don't find the " << i << endl;
    } else {
        cout << "position: " << vi_last - vi.begin() + 1 << endl;
    }

    string str = "world";
    auto ls_last = Find(ls.begin(), ls.end(), str);
    if (ls.end() == ls_last) {
        cout << "Don't find the " << str << endl;
    } else {
        int ls_pos = 1;
        while (ls.begin() != ls_last) {
            ++ls_pos;
            --ls_last;
        }
        cout << "position: " << ls_pos << endl;
    }


    return 0;
}

