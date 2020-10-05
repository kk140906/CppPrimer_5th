/*
 * Exercise 9.38 验证vector中是如何实现自动调整capacity
 */
#include <iostream>
#include <vector>

using namespace std;
// vector容量增长策略为：
// 当容器内元素的个数与容器相等时，此时再添加新的元素会使vector的容量大小增长为当前元素的2倍,当删除元素时并不会使容器的容量减少

int main(int argc, char **argv) {
    vector<int> v_int;
    cout << "未插入前容器容量大小:" << v_int.capacity() << endl;
    for (unsigned i = 0; i <= 5; ++i) {
        v_int.push_back(i);
        cout << "插入" << i + 1 << "个元素后，容量大小为:" << v_int.capacity() << endl;
    }
    for (unsigned i = 0; i <= 5; ++i) {
        v_int.pop_back();
        cout << "删除" << i + 1 << "个元素后，容量大小为:" << v_int.capacity() << endl;
    }
    return 0;
}



