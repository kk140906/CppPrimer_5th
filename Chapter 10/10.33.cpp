/*
 * Exercise 10.33 编写程序，接受三个参数,一个输入文件和两个输出文件的文件名,输入文件中保存的数据应该为整数
 * 使用istream_iterator读取输入文件，使用ostream_iterator将奇数写入到第一个文件中，每个值后紧跟一个空格
 * 使用ostream_iterator将偶数写入到第二个文件中，每个值占据一行
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

void splitNumber(const string &inFileName, const string &outOddFileName, const string &outEvenFileName) {
    ifstream in_file(inFileName, fstream::in);
    if (!in_file) {
        cout << "输入文件流:" << inFileName << "打开失败." << endl;
        return;
    }
    ofstream out_file_odd(outOddFileName, fstream::out), out_file_even(outEvenFileName, fstream::out);
    if (!out_file_odd) {
        cout << "输出文件流:" << outOddFileName << "打开失败." << endl;
        return;
    }
    if (!out_file_even) {
        cout << "输出文件流:" << outEvenFileName << "打开失败." << endl;
        return;
    }
    istream_iterator<int> iterator_infile(in_file), iterator_eof;
    // 输出流迭代器会忽略迭代器的解引用，前置++ 和后置++运算,但是为了便于语义理解，通常会加上
    ostream_iterator<int> iterator_out_odd(out_file_odd, " "), iterator_out_even(out_file_even, "\n");
    for_each(iterator_infile, iterator_eof, [iterator_out_odd, iterator_out_even](const int &ci) mutable {
        // 等价于 iterator_out_odd = ci;
        if (ci % 2) *iterator_out_odd++ = ci;
        else
            // 等价于 iterator_out_even = ci;
            *iterator_out_even++ = ci;
    });
}

int main(int argc, char **argv) {
    splitNumber("10.33.txt", "10.33.odd.txt", "10.33.even.txt");
    return 0;
}


