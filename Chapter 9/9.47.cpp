/*
 * Exercise 9.47 编写程序，首先查找string “ab2c3d7r4E6"中的每个数字字符，然后查找其中每个字母字符
 * 编写两个版本，第一个版本使用find_first_of函数，第二个版本使用find_first_not_of
 */
#include <iostream>
#include <string>

using namespace std;

void findCharacterInBase(const string &str, const string &base);

void findCharacterOutBase(const string &str, const string &base);

int main(int argc, char **argv) {
    string number{"0123456789"};
    string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string str("ab2c3d7r4E6");
    cout << "查找数字字符：" << endl;
    findCharacterInBase(str, number);
    cout << "查找字母字符：" << endl;
    findCharacterInBase(str, alphabet);
    cout << "查找数字字符：" << endl;
    findCharacterOutBase(str, alphabet);
    cout << "查找字母字符：" << endl;
    findCharacterOutBase(str, number);
    return 0;
}


void findCharacterInBase(const string &str, const string &base) {
    decltype(str.size()) pos = 0;
    // find_first_of是查找在字符串str中从pos位置开始第一个出现的base中任意字符的字符所在的位置
    // 如果str中未找到任何base中的字符则返回string::npos，因此据此可以判断是否找到对应的字符
    // 如果找到了就更新pos的位置，让其从找到的字符之后继续查找是否还有匹配的字符
    // 该判定条件不需要担心pos的大小会比str.size()大，find_first_of函数内部会进行比较，
    // 如果发现比str.size()大，直接返回string::npos
    while ((pos = str.find_first_of(base, pos)) != string::npos) {
        // 注意find_first_of返回的位置是从0开始计数，
        // 因此，++pos不仅将位置转换为容易理解的第几个位置，同时保证后续查找时从已经找到的字符位置之后开始查找
        cout << "字符:" << str[pos] << " 位于第" << ++pos << "个位置" << endl;
    }
}

void findCharacterOutBase(const string &str, const string &base) {
    decltype(str.size()) pos = 0;
    // find_first_not_of是查找在字符串str中从pos位置开始第一个出现的非base中任意字符的字符所在的位置
    while ((pos = str.find_first_not_of(base, pos)) != string::npos) {
        cout << "字符:" << str[pos] << " 位于第" << ++pos << "个位置" << endl;
    }
}
