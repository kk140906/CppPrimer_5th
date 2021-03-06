/**
 * Exercise 9.46 编写一个函数，接受一个表示名字的 string 参数和两个分别表示前缀(如"Mr." 或"Ms.")和后缀(如 "Jr." 或"III")的字符串。
 * 使用位置和长度来管理string，并且只用insert函数，将生成的新string返回 。
 */
#include <iostream>
#include <string>

using namespace std;

// 返回值不能是引用，因为形参不是引用或者指针，返回对局部变量的引用是非法的，可能导致未定义的行为
// 如果把形参声明为引用，那么s将会被更改，同时也没必要使用函数返回值去返回生成的string了
string addNameInfo(string s, const string &prefix, const string &suffix);


int main(int argc, char **argv) {
    string str1("xiao"), str2;
    str2 = addNameInfo(str1, "MR.", "ming");
    cout << "插入前：" << str1 << endl;
    cout << "插入后：" << str2 << endl;
    return 0;
}

string addNameInfo(string s, const string &prefix, const string &suffix) {
    decltype(s.size()) pos = 0;
    auto pre_size = prefix.size(), s_size = s.size();
    s.insert(pos, prefix);
    pos += pre_size + s_size;
    s.insert(pos++, " ");
    return s.insert(pos, suffix);
}



