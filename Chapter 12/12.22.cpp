/**
 * Exercise 12.22 为了能让StrBlobPtr使用const StrBlob,修改并定义一个StrBlobPtr的类，使其能够指向const StrBlob
 * */

#include <iostream>
#include <string>

#include "../common/header/StrBlob.h"
#include "../common/header/StrBlobPtr.h"

using namespace std;

int main(int argc, char **argv) {
    const StrBlob b1 = {"a", "cc", "dd", "?"};
    for (auto begin = b1.cbegin(), end = b1.cend(); begin != end; ++begin) {
        cout << *begin << " ";
    }
    return 0;
}


