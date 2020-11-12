/**
 * @details: Exercise 17.25 重写你的电话号码程序，使之只输出每个人的第一个号码
 * @details: Exercise 17.26 重写你的电话号码程序，使之只输出除了第一个以外的所有的匹配个号码
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <regex>

using namespace std;

bool ValidPhoneNumber(const smatch &m) {
    // 2根据模式是一定会匹配成功的
    // 如果1没有匹配成功，那2如果是空则是有效的，
    // 由于一行存在多个匹配，如果1没匹配成功，而2却非空,那么还需要判断一下2中是否是空白字符来进一步判断是否是合法的号码
    // 如果1匹配成功，那么只在2的大小为1且为非空格的时候去比较2和4的字符串是否相同，不相同则认为非法
    if (m[1].matched) {
        return m[3].matched && m[4].matched && m[5].matched &&
               (m[2].str().size() == 1 && m[2].str() != " " ? m[2].str() == m[4].str() : 1);
    } else {
        return m[3].matched && m[4].matched && m[5].matched && m[2].str().empty() ||
               (m[2].str() != "-" && m[2].str() != ".");
    }
}

int main() {

    string phone_number;
    regex r("(\\(\\d{3}\\))?([.-]?|\\s*)(\\b\\d{3})([.-]?|\\s+)(\\d{4}\\b)");
    smatch m;
    cout << "请输入电话号码:" << endl;
    while (getline(cin, phone_number)) {
        regex_search(phone_number, m, r);
        if (ValidPhoneNumber(m)) {
            cout << "valid: " << m[0].str() << endl;
            string format_str = m[1].matched ? "$1-$3-$5" : "$3-$5";
            cout << "formatted: " << regex_replace(m[0].str(), r, format_str) << endl;
        } else {
            cout << "not valid: " << m[0].str() << endl;
        }

        cout << "除了第一个以外匹配的号码: " << endl;
        sregex_iterator it(phone_number.begin(), phone_number.end(), r), end;
        for (; ++it != end;) {
            if (ValidPhoneNumber(*it)) {
                cout << "valid: " << it->str() << endl;
                string format_str = (*it)[1].matched ? "$1-$3-$5" : "$3-$5";
                cout << "formatted: " << regex_replace(it->str(), r, format_str) << endl;
            }
        }

        cout << "请输入电话号码:" << endl;
    }

    return 0;
}

