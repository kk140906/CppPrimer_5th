/*
 * Exercise 8.11 编写函数，以读模式打开一个文件，将其内容读入到一个string 的vector中，将一行作为一个独立的元素保存在vector中
 * 然后定义一个函数从vector中以istringstream的形式一个一个读取内容,把istringstream定义移动到循环外定义
 */
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void readLineToVector(const string &filename, vector<string> &vec) {
    string buf;
    ifstream ifs(filename);
    while (getline(ifs, buf)) {
        vec.push_back(buf);
    }
    // 读取完毕关闭文件流，如果不关闭，那么该文件流就无法被后面的对象接着使用；
    // 由于文件流离开它的作用域会自动失效，所以最好在函数内部打开文件流
    // 函数结束时，会自动调用close,避免出错。
//    ifs.close();
}

void readWordFromVector(vector<string> &vec) {
    string buf;
    // 移动到循环外定义
    istringstream iss;
    for (const auto &vec_item : vec) {
        // 循环内需要将string 对象拷贝到istringstream中
        // 一行的内容读取完毕会触发eofbit置位，下一次输入操作就会失败，每次退出循环需要重置iostate
        iss.str(vec_item);
        while (iss >> buf) {
            cout << buf << endl;
        }
        iss.clear();
    }
}

int main(int argc, char **argv) {
    string filename("8.4.txt");
    cout << "读取行:" << endl;
    vector<string> vec_line;
    readLineToVector(filename, vec_line);
    for (const auto &vec : vec_line) {
        cout << vec << endl;
    }
    cout << "读取词:" << endl;
    readWordFromVector(vec_line);
    return 0;
}
