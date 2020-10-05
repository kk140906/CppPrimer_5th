/*
 * Exercise 9.31 编写删除偶数值元素并复制奇数值元素的函数用于list或forward_list
 */
#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

void copyOddFromList(list<int> &l_int);

void copyOddFromForwardList(forward_list<int> &fl_int);

int main(int argc, char **argv) {
    list<int> l_int{1, 2, 3, 4};
    copyOddFromList(l_int);
    for (auto il : l_int) {
        cout << il << " ";
    }
    cout << endl;
    forward_list<int> fl_int{1, 2, 3, 4};
    copyOddFromForwardList(fl_int);
    for (auto il : fl_int) {
        cout << il << " ";
    }
    return 0;
}

// list是双向链表，erase会删除当前的迭代器指向的对象然后指向下一个对象，
// 而insert会在当前迭代器位置的插入新的对象,同时返回指向插入对象的迭代器
void copyOddFromList(list<int> &l_int) {
    for (auto curr = l_int.cbegin(); curr != l_int.cend();) {
        if (*curr % 2) {
            curr = l_int.erase(curr);
        } else {
            curr = l_int.insert(curr, *curr);
            ++ ++curr;
        }
    }
}

// forward_list是单向列表，需要删除和插入新的结点需要知道上一个结点的信息
void copyOddFromForwardList(forward_list<int> &fl_int) {
    auto prev = fl_int.before_begin();
    for (auto curr = fl_int.cbegin(); curr != fl_int.cend();) {
        if (*curr % 2) {
            curr = fl_int.erase_after(prev);
        } else {
            prev = fl_int.insert_after(curr, *curr);
            curr = prev;
            ++curr;
        }
    }
}

