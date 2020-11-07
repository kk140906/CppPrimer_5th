/**
 * @details : Exercise 16.48 编写自己版本的debug_rep函数
 */

#include <iostream>
#include <string>
#include <sstream>

#define Exercise1665

using namespace std;

template<typename T_>
string debug_rep(const T_ &arg);

template<typename T_>
string debug_rep(T_ *arg);

string debug_rep(const string &arg);

#ifndef Exercise1665
string debug_rep(char *arg);

string debug_rep(const char *arg);
#else

template<>
string debug_rep(char *arg);

template<>
string debug_rep(const char *arg);

#endif

int main() {
    cout << "----------testing----------" << endl;
    string str("hello");
    cout << debug_rep(str) << endl;
    cout << endl;

    cout << "----------testing----------" << endl;
    string *p_str = &str;
    cout << debug_rep(p_str) << endl;
    cout << endl;

    cout << "----------testing----------" << endl;
    const string *cp_str = &str;
    cout << debug_rep(cp_str) << endl;
    cout << endl;

    cout << "----------testing----------" << endl;
    int i = 42;
    cout << debug_rep(i) << endl;
    cout << endl;

    cout << "----------testing----------" << endl;
    char *p_c = const_cast<char *>("hello");
    cout << debug_rep(p_c) << endl;
    cout << endl;

    cout << "----------testing----------" << endl;
    cout << debug_rep("hello world") << endl;
    cout << endl;

    return 0;
}


template<typename T_>
string debug_rep(const T_ &arg) {
    cout << __PRETTY_FUNCTION__ << endl;
    ostringstream ret;
    ret << arg;
    return ret.str();
}

template<typename T_>
string debug_rep(T_ *arg) {
    cout << __PRETTY_FUNCTION__ << endl;
    ostringstream ret;
    ret << "Pointer address: " << arg << ",";
    if (arg) {
        ret << "Value: " << debug_rep(*arg);
    } else {
        ret << "nullptr";
    }
    return ret.str();
}

string debug_rep(const string &arg) {
    cout << __PRETTY_FUNCTION__ << endl;
    return '"' + arg + '"';
}

#ifndef Exercise1665
string debug_rep(char *arg) {
    cout << __PRETTY_FUNCTION__ << endl;
    return debug_rep(string(arg));
}

string debug_rep(const char *arg) {
    cout << __PRETTY_FUNCTION__ << endl;
    return debug_rep(string(arg));
}
#else

template<>
string debug_rep(char *arg) {
    cout << "char * ============== : " << __PRETTY_FUNCTION__ << endl;
    return debug_rep(string(arg));
}

template<>
string debug_rep(const char *arg) {
    cout << "const char * ============= : " << __PRETTY_FUNCTION__ << endl;
    return debug_rep(string(arg));
}

#endif