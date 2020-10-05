/*
 * Exercise 6.33 编写一个递归函数，输出vector对象的内容
 */
#include <iostream>
#include <vector>

using namespace std;

void outVectorContents(const vector<int> &vec, const int index);

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    outVectorContents(vec, 0);
    return 0;
}

void outVectorContents(const vector<int> &vec, const int index) {
    auto size = vec.size();
    if (index < size) {
        cout << vec[index] << endl;
        outVectorContents(vec, index + 1);
    }
}
