/**
 * Exercise 9.16 比较list<int> 和vector<int>的元素是否相等
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 其他思路，可以使用范围迭代器创建一个vector<int>的对象，然后直接比较这两个vector是否相等即可
bool compare(const list<int> &element1, const vector<int> &element2) {
    if (element1.size() == element2.size()) {
        // list不支持下标运算，只能通过迭代器进行遍历
        auto e1_b = element1.cbegin();
        auto e1_e = element1.cend();
        auto e2_b = element2.cbegin();
        while (e1_b != e1_e) {
            if (*e1_b++ != *e2_b++) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    list<int> l_int{2, 4, 5};
    vector<int> v_int{2, 4, 5};
    cout << compare(l_int, v_int) << endl;
    return 0;
}


