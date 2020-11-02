/**
 * Exercise 10.5 用equal函数判断两个序列中是否存在相同的元素，
 * equal接收的参数是迭代器，因此可用来比较不同类型的容器，甚至容器内的元素也可以是不同类型，只要元素能够使用==进行判断即可
 * 而却equal仅接收第二个序列的首位置，那么就意味着比较的长度会与第一个序列的长度相同，同时第二个序列的长度至少要比传输的迭代器范围大
 * 注意equal是要求所有比对的元素全部相等才会返回true
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main(int argc, char **argv) {
    vector<int> v_int{2, 3, 65, 5, 2, 5, 6, 2, 3, 4};
    vector<int> v_double{2, 3, 65};
    // 注意equal是要求所有比对的元素全部相等才会返回true
    cout << equal(v_double.cbegin(), v_double.cend(), v_int.cbegin()) << endl;
    vector<const char *> v_char1{"hello", "world", "yy"};
    vector<const char *> v_char2{"hello"};
    cout << equal(v_char2.cbegin(), v_char2.cend(), v_char1.cbegin()) << endl;
    return 0;
}


