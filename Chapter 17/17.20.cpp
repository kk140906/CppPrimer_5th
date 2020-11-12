/**
 * @details: Exercise 17.20 编写自己版本的验证电话号码的程序
 * @details: Exercise 17.22 重写你的电话号码程序，使之允许在号码的三个部分中间放置任意的空白字符
 * @details: Exercise 17.24 编写你自己版本的重排电话号码格式的程序
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <regex>

using namespace std;

bool ValidPhoneNumber(smatch &m) {
    // 2根据模式是一定会匹配成功的
    // 如果1没有匹配成功，那2如果是空则是有效的，相反，如果1没匹配成功，而2却非空说明无效
    // 如果1匹配成功，那么只在2的大小为1且为非空格的时候去比较2和4的字符串是否相同，不相同则认为非法
    if (m[1].matched) {
        return m[3].matched && m[4].matched && m[5].matched &&
               (m[2].str().size() == 1 && m[2].str() != " " ? m[2].str() == m[4].str() : 1);
    } else {
        return m[3].matched && m[4].matched && m[5].matched && m[2].str().empty();
    }
}

int main() {

    string phone_number;
    regex r("(^\\(\\d{3}\\))?([.-]?|\\s*)(\\b\\d{3})([.-]?|\\s+)(\\d{4}$)");
    smatch m;
    cout << "请输入电话号码:" << endl;
    while (getline(cin, phone_number)) {
        regex_search(phone_number, m, r);
        if (ValidPhoneNumber(m)) {
            cout << "valid: " << m[0].str() << endl;
            string format_str = m[1].matched ? "$1-$3-$5" : "$3-$5";
            cout << "formatted: " << regex_replace(phone_number, r, format_str) << endl;
        } else {
            cout << "not valid: " << m[0].str() << endl;
        }
        cout << "请输入电话号码:" << endl;
    }

    return 0;
}

