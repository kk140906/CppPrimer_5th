/**
 * Exercise 8.7 打开8.4.txt的内容，然后观察其内容
 * Exercise 8.8 采用追加到文件末尾的方式，将一些字符串保存到8.4.txt中
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char **argv) {
    string filename("8.4.txt");
    ofstream ofs(filename, ofstream::out);
    if (!ofs) return -1;
    ofs.close();
    system("pause");
    ofs.open(filename, ofstream::out | ofstream::app);
    ofs << "hello world" << endl;
    ofs.close();
    ofs.open(filename, ofstream::out | ifstream::app);
    ofs << "hello kk" << endl;
    ofs.close();
    ofs.open(filename, ofstream::out | ofstream::app);
    ofs << "today is a good day" << endl;
    cout << "内容写入完毕" << endl;
    return 0;
}
