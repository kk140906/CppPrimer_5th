/**
 * Exercise 9.27 查找并删除forward_list<int>中的奇数
 */
#include <iostream>
#include <forward_list>

using namespace std;

int main(int argc, char **argv) {

    forward_list<int> fl_int{2, 3, 4, 1, 4, 3, 5, 5, 6, 7};
    // forward_list是单向链表，标准库只有erase_after函数，删除的是当前结点的下一个结点的数据
    // 所以，当发现当前结点是奇数无法被删除，因此需要通过前一个结点的信息来删除当前结点
    for (auto pre = fl_int.before_begin(), cur = fl_int.begin(); cur != fl_int.end();) {
        if (*cur % 2) {
            cur = fl_int.erase_after(pre);
        } else {
            pre = cur;
            ++cur;
        }
    }

    cout << "forward_list中元素为:" << endl;
    for (const auto &il : fl_int) {
        cout << il << " ";
    }
    cout << endl;
    return 0;
}


