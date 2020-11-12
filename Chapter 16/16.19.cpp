/**
 * @details : Exercise 16.19 编写函数接受一个容器的引用，打印容器中的元素，使用容器的size_type和size成员来控制打印元素的循环
 * @details : Exercise 16.20 重写16.19的练习，使用begin和end返回的迭代器来控制循环
 */
#include <iostream>
#include <string>
#include <vector>

template<typename T_>
void Print(const std::vector<T_> &vec) {
    for (typename std::vector<T_>::size_type i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

template<typename Tp_>
void Print(Tp_ begin, Tp_ end) {
    while (begin != end) {
        std::cout << *begin++ << " ";
    }
    std::cout << std::endl;
}

using namespace std;

int main() {

    vector<int> vi{1, 34, 56, 7, 32, 5};
    vector<string> vs{"hello", "world"};

    Print(vi);
    Print(vs.begin(), vs.end());
    return 0;
}

