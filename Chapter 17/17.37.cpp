/**
 * @details: Exercise 17.37 用未格式化版本的getline，逐行读取一个文件。
 *           测试你的程序，给定一个文件既包含空行又包含长度超过你传递给getline的字符数组大小的行
 * @details: Exercise 17.38 扩展17.37的程序，将读入的单词打印到它所在的行
 */
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string file("17.33.mappedFile.txt");
    ifstream in_file(file);
    if (!in_file) {
        cout << file << " open fail." << endl;
        exit(-1);
    }
    const int kArrSize = 10;
    char arr[kArrSize];

    while (!in_file.eof()) {
        // 通过'\n'字符标记新的一行结束
        in_file.getline(arr, kArrSize, '\n');

        for (int i = 0; i < in_file.gcount(); ++i) {
            cout << arr[i];
        }
        // iostream 不抛出异常，一旦流发生异常，不能直接通过异常捕获去获取流状态
        if (!in_file.good()) {
            // 未格式化的操作将最后一个位置留给了字符串的结束字符，最多只能读取字符数组大小减一的字符数
            if (in_file.gcount() == kArrSize - 1) {
                in_file.clear();
            }
        } else {
            // 只有在流状态正常的情况下才刷新缓冲区，保证长度超过字符数组大小时的所有内容显示在同一行
            cout << " " << endl;
        }
    }


    return 0;
}

