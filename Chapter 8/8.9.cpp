/**
 * Exercise 8.9 编写一个函数，接收istringstream & 参数，返回类型也是istringstream &
 * 函数从给定的流里面读取数据，直到遇到文件结束标识时停止。它将读取的数据打印在标准输出上
 * 完成这些操作后，在返回流之前对流进行复位，使其处于有效状态
 * */
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

istringstream &read(istringstream &iss) {
    string str;
    while (iss >> str) {
    }
    cout << "读取的数据内容为：" << str << endl;
    cout << "复位流状态前:"
         << "是否到达文件结尾:" << iss.eof() << ","
         << "是否发生I/O错误：" << iss.fail() << ","
         << "是否发生系统级错误：" << iss.bad() << ","
         << endl;
    iss.clear();
    cout << "复位流状态后:"
         << "是否到达文件结尾:" << iss.eof() << ","
         << "是否发生I/O错误：" << iss.fail() << ","
         << "是否发生系统级错误：" << iss.bad() << ","
         << endl;
    return iss;
}

int main(int argc, char **argv) {
    string buf;
    cin >> buf;
    istringstream record(buf);
    read(record);
    return 0;
}