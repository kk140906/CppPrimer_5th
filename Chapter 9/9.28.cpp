/*
 * Exercise 9.28 编写函数，接受一个forward_list<string>和两个string共三个参
 * 数。函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个
 * string之后的位置。若第1个string未在链表中 ，则将第二个string插入到链表末尾 。
 */
#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void insertToForwardList(forward_list<string> &fl_str, const string &str1, const string &str2);


int main(int argc, char **argv) {

    forward_list<string> fl_str{"hello", "world", "!", "today", "is", "a", "day"};
    insertToForwardList(fl_str, "a", "good");
    cout << "forward_list中元素为:" << endl;
    for (const auto &il : fl_str) {
        cout << il << " ";
    }
    cout << endl;
    insertToForwardList(fl_str, "to", "good");
    cout << "forward_list中元素为:" << endl;
    for (const auto &il : fl_str) {
        cout << il << " ";
    }
    cout << endl;
    return 0;
}

void insertToForwardList(forward_list<string> &fl_str, const string &str1, const string &str2) {
    decltype(fl_str.cbegin()) prev_iter;
    for (auto begin = fl_str.cbegin(); begin != fl_str.cend(); ++begin) {
        if (*begin == str1) {
            begin = fl_str.insert_after(begin, str2);
            return;
        }
        prev_iter = begin;
    }
    fl_str.insert_after(prev_iter, str2);
}

