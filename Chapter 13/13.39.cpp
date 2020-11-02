/**
 * Exercise 13.39 仿照标准库容器vector编写自己版本的StrVec，包括自己版本的reverse,capacity,resize等
 * Exercise 13.40,为StrVec类添加一个构造函数，它接受一个initializer_list<string>参数
 * Exercise 13.43,使用for_each和lambda重写free函数
 * Exercise 13.49,为你的StrVec类添加一个移动构造函数和移动赋值运算符
 * */

#include "../common/header/StrVec.h"

using namespace std;

int main(int argc, char **argv) {
    StrVec s1, s2, s3({"a", "b", "c", "d"}), s4;
    // push_back内部直接移动的内容不包含对象的拷贝或者移动
    s1.push_back("aa");
    s1.push_back("bb");
    cout << "-----移动赋值运算符----" << endl;
    s2 = std::move(s1);
    cout << "-----移动构造函数-----" << endl;
    StrVec s5 = std::move(s2);
    cout << "-----拷贝赋值运算符----" << endl;
    s4 = s3;


    return 0;
}



