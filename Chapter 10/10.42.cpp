/**
 * Exercise 10.42 使用list实现去除重复单词
 * */
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <iterator>

using namespace std;

void eraseDuplicateWord(list<string> &ls) {
    ls.sort();
    ls.unique();
}

int main(int argc, char **argv) {
    list<string> ls{"hello", "world", "today", "hello", "hh", "world", "kk", "hh"};
    eraseDuplicateWord(ls);
    ostream_iterator<string> iterator_cout(cout, " ");
    copy(ls.cbegin(), ls.cend(), iterator_cout);
    cout << endl;
    return 0;
}


