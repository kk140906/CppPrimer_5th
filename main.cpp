
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <regex>
#include <windows.h>

using namespace std;


int main(int argc, char **argv) {
    auto t = GetTickCount();
    string phone("sfsdfa3694512");
    regex r("[[:alpha:]]+");
    smatch sm;
    regex_search(phone, sm, r);
    cout << sm.format("$0") << endl;

    return 0;
}


