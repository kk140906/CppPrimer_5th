/*
 * Exercise 10.29 使用流迭代器读取一个文本文件，存入一个vector中的string里
 * */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;


int main(int argc, char **argv) {
    // 创建文件流对象
    ifstream infile("10.29.txt");
    // 利用文件流对象创建输入流迭代器
    istream_iterator<string> iterator_infile(infile), eof;
    // 利用输入流迭代器范围创建创建vector<string>对象
    vector<string> v_str(iterator_infile, eof);
    // 创建一个输入流迭代器，并在输出的结尾附加一个空格
    ostream_iterator<string> iterator_out(cout, " ");
    // 通过拷贝的方式打印容器内每一个元素
    copy(v_str.cbegin(), v_str.cend(), iterator_out);
    cout << endl;
    return 0;
}


