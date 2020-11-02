/**
 * Exercise 8.4 编写函数，以读模式打开一个文件，将其内容读入到一个string 的vector中，将一行作为一个独立的元素保存在vector中
 * Exercise 8.5 再定义一个函数，将内容以一个词作为一个独立的元素保存到vector中
 */
#include <fstream>
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

void readWordToVector(const string &filename, vector<string> &vec) {
    string buf;
    ifstream ifs(filename);
    while (ifs >> buf) {
        vec.push_back(buf);
    }
    // 文件流离开其作用域时会自动调用close，显示调用也不会有问题
    ifs.close();
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
    vector<string> vec_word;
    readWordToVector(filename, vec_word);
    for (const auto &vec : vec_word) {
        cout << vec << endl;
    }
    return 0;
}
