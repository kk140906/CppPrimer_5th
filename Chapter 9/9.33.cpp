/*
 * Exercise 9.33
 */
#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

int main(int argc, char **argv) {
    list<int> l_int{1, 2, 3, 4, 6, 10};
    for (auto begin = l_int.cbegin(); begin != l_int.cend(); ++begin) {
        ++begin;
        // 不将insert的返回的结果传递给begin，将不会使begin迭代器更新
        l_int.insert(begin, 32);
//        begin = l_int.insert(begin,32);
    }

    for (auto il : l_int) {
        cout << il << " ";
    }
    return 0;
}



