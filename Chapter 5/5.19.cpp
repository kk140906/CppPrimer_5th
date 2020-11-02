/**
 * Exercise 5.19 编写一段程序，使用do while 循环重复执行以下任务：首先提示用户输入两个string 对象，然后挑出较短的输出
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    do {
        cout << "请输入两个字符串，以空格或者回车间隔：" << endl;
        string str1, str2;
        cin >> str1 >> str2;
        cout << "较短的字符串为：" << (str1.size() > str2.size() ? str2 : str1) << endl;
    } while (true);
    return 0;
}
