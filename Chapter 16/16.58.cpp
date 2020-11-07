/**
 * @details : Exercise 16.58 为你的StrVec和Vec类添加emplace_back函数
 */

#include <iostream>
#include <string>

#include "../common/header/StrVec.h"
#include "../common/header/vec.h"

using namespace std;


int main() {
    StrVec sv;
    sv.emplace_back("hello");
    cout << sv[0] << endl;

    Vec<int> vi;
    vi.emplace_back(42);
    cout << vi[0] << endl;

    return 0;
}

