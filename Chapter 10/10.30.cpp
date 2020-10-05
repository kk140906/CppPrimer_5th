/*
 * Exercise 10.30 使用流迭代器从标准输入中读取一个整数序列，然后进行排序，利用copy将结果输出到标准标准输出中
 * Exercise 10.31 改写exercise 10.30 使其只打印不重复的元素，使用unique_copy代替copy
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;


int main(int argc, char **argv) {
    // 提示信息只能在流迭代器创建之前打印，一旦流迭代器创建就开始监测标准输入了
    cout << "请输入一系列整数:" << endl;
    istream_iterator<int> iterator_cin(cin), eof;
    vector<int> v_int(iterator_cin, eof);
    sort(v_int.begin(), v_int.end());
    ostream_iterator<int> iterator_cout(cout, " ");
    cout << "排序后的整数序列为：" << endl;
    copy(v_int.cbegin(), v_int.cend(), iterator_cout);
    cout << endl;
    cout << "排序后不包含重复元素的整数序列为：" << endl;
    unique_copy(v_int.cbegin(), v_int.cend(), iterator_cout);
    cout << endl;
    return 0;
}


