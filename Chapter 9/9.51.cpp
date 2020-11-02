/**
 * Exercise 9.51 设计一个类，它有三个unsigned成员，分别表示年,月,日，
 * 为其编写构造函数，接受一个表示日期的string参数，构造函数应该能够处理不同数据格式
 * 例如 january 1,1990,1/1/1990，Jan 1 1900等
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findSubString(const string &str, string::size_type &pos, const string &base);

vector<string> getDateSubstring(const string &str);

unsigned matchAlphabetMonth(const string &str);

vector<unsigned> toUnsigned(vector<string> &vec_str);

class Date {
public:
    Date() = default;

    //构造函数支持的日期排列形式为：月-日-年，日-月-年，年-月-日
    explicit Date(const string &str);

    string getDate() const {
        return to_string(year) + " 年 " + to_string(month) + " 月 " + to_string(day) + " 日";
    }

private:
    unsigned year, month, day;
};

Date::Date(const string &str) {
    auto date_str = getDateSubstring(str);
    auto date_unsigned = toUnsigned(date_str);

    // TODO:拿到数据如何进行年月日对应关系比较复杂,优化该方式
    if (date_unsigned.size() > 3) {
        year = date_unsigned[1];
        month = date_unsigned[2];
        day = date_unsigned[0];
    } else {
        // 全数字日期类型分两种情况处理，
        // 一种是把输入的字符串按照"年-月-日"进行区分，
        // 一种是把输入的字符串按照"日-月-年"进行区分
        if (date_unsigned[0] > date_unsigned[2]) {
            year = date_unsigned[0];
            day = date_unsigned[2];
        } else {
            year = date_unsigned[2];
            day = date_unsigned[0];
        }
        month = date_unsigned[1];
    }
}

int main(int argc, char **argv) {
    string date_str("January 21,1990");
    date_str = "21/1/1990";
    date_str = "21,1990,Jan";
    date_str = "2006年7月12日";
    date_str = "1999-12-01";
    date_str = "1992,12/01";
    Date date_obj(date_str);
    cout << date_obj.getDate();
    return 0;
}

unsigned matchAlphabetMonth(const string &str) {
    vector<string> vec_months{"January", "February", "March", "April", "May", "June",
                              "July", "August", "September", "October", "November", "December"};
    for (decltype(vec_months.size()) pos = 0; pos < vec_months.size(); ++pos) {
        if (vec_months[pos].find(str) != string::npos) {
            return pos + 1;
        }
    }
    // 返回一个不正确的数字表示输入错误的str
    return 99;
}

string findSubString(const string &str, unsigned long long int &pos, const string &base) {
    auto tmp_pos = str.find_first_of(base, pos);
    // pos是引用，保证找到第一个包含base任意字符的情况才更新pos
    if (tmp_pos == string::npos) {
        return string("");
    }
    pos = tmp_pos;
    auto end = str.find_first_not_of(base, pos);
    // 从pos到开始如果都没找到第一个不包含base任意字符的情况，那么认为已经遍历完毕
    if (end == string::npos) {
        end = str.size();
    }
    return str.substr(pos, end - pos);
}

vector<string> getDateSubstring(const string &str) {
    // 如果全是数字类型的字符串容器内部按照日、月、年的顺序排列或者年月日的顺序排列
    // 如果包含字母类型的月份，容器内部按照日、年、月的顺序排列
    vector<string> vec_str;
    string number{"0123456789"};
    string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    decltype(str.size()) pos = 0;
    string sub_str;
    // 循环抽取年月日数字字符串
    while (!(sub_str = findSubString(str, pos, number)).empty()) {
        pos += sub_str.size();
        vec_str.push_back(sub_str);
    }
    // 最后pos重置为0，判断一下是否存在字母字符的月份
    pos = 0;
    sub_str = findSubString(str, pos, alphabet);
    // 如果不为空，那么通常说明只找到日和年的信息，容器大小此时为2，如果不是此情况，那么表示出现错误
    if (!sub_str.empty() && vec_str.size() == 2) {
        vec_str.push_back(sub_str);
        // 多压入一个字符串作为包含字母月份的标志,
        // 标志是通过常量的形式压入容器中，使用emplace创建一个对象压入比较合适
        vec_str.emplace_back("containMonthString");
    }
    return vec_str;
}

vector<unsigned> toUnsigned(vector<string> &vec_str) {
    vector<unsigned> vec_unsigned;
    for (const auto &str : vec_str) {
        // string对象如果不能转换成对应的数值类型则会抛出invalid_argument错误
        try {
            vec_unsigned.push_back(stoul(str));
        }
        catch (invalid_argument &error) {
            // 包含字母月份，需要进行字母与月份的匹配
            vec_unsigned.push_back(matchAlphabetMonth(str));
        }
    }
    return vec_unsigned;
}
