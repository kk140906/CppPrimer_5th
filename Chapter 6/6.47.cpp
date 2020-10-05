/*
 * Exercise 6.47 编写一个递归函数，输出vector对象的内容,通过NDEBUG宏控制输出日志
 */
#include <iostream>
#include <vector>
//#define NDEBUG

using namespace std;

void outVectorContents(vector<int> &vec);

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    outVectorContents(vec);
    return 0;
}

void outVectorContents(vector<int> &vec) {
#ifndef NDEBUG
    cout << "vector size is :" << vec.size() << endl;
#endif
    if (!vec.empty()) {
        auto last = *(vec.cend() - 1);
        vec.pop_back();
        outVectorContents(vec);
        cout << last << endl;
    }
}
