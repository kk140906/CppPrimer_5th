/**
 * @details : Exercise 16.16 将StrVec重写为模板
 */
#include <iostream>
#include <string>
#include <algorithm>

#include "../common/header/vec.h"

using namespace std;

int main() {

    Vec<string> s1, s2, s3({"a", "b", "c", "d"}), s4;
    // push_back内部直接移动的内容不包含对象的拷贝或者移动
    s1.push_back("aa");
    s1.push_back("bb");
    cout << "-----移动赋值运算符----" << endl;
    s2 = std::move(s1);
    cout << "-----移动构造函数-----" << endl;
    Vec<string> s5 = std::move(s2);
    cout << "-----拷贝赋值运算符----" << endl;
    s4 = s3;
    s4 = {"a", "b", "c", "d"};
    return 0;
}

