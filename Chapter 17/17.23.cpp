/**
 * @details: Exercise 17.23 编写查找邮政编码的正则表达式，美国邮政编码可以由5位或者9位数组成，前5位数字和后四位数字中间以短横线连接
 * @details: Exercise 17.27 编写程序将9位数的格式转换为ddddd-dddd
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <regex>

using namespace std;


int main() {

    string post_number;
    regex r("(^\\d{5}$)|(^\\d{5}(\\W+|-?\\d{4})$)");
    smatch m;
    cout << "请邮政号码:" << endl;
    while (getline(cin, post_number)) {
        regex_search(post_number, m, r);
        if (m[0].matched) {
            cout << "valid:" << m[0].str() << endl;
            auto matched_str = m[0].str();
            // 可以直接在字符串里面插入，不需要使用正则表达式再搜索一次，这里只是为了练习正则表达式的regex_replace
            if (matched_str.size() == 9) {
                regex r2("(^\\d{5})(\\d{4}$)");
                smatch m2;
                regex_search(matched_str, m2, r2);
                cout << "formatted: " << regex_replace(matched_str, r2, "$1-$2") << endl;
            } else {
                cout << "formatted: " << matched_str << endl;
            }
        } else {
            cout << "no valid: " << post_number << endl;
        }
        cout << "请输入邮政号码:" << endl;
    }

    return 0;
}

