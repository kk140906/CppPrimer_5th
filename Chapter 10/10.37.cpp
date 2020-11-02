/**
 * Exercise 10.37 给定一个包含10个元素的vector,把位置3到7的元素按照逆序拷贝到一个list中
 * */
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    vector<int> v_int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> l_int;
    copy(v_int.crbegin() + 3, v_int.crbegin() + 8, back_inserter(l_int));
    for_each(l_int.cbegin(), l_int.cend(), [](const int &ci) { cout << ci << " "; });
    cout << endl;
    return 0;
}


