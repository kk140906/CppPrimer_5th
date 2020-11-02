/**
 * Exercise 10.7
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


int main(int argc, char **argv) {
    vector<int> vec;
    list<int> lst;
    int i;
    cout << "请输入存入list的数值:" << endl;
    while (cin >> i) {
        lst.push_back(i);
    }
    cout << "vector容器中的数值为:" << endl;
    // copy函数第三个形参标识了copy的目的地的起始位置，它不改变容器的大小
    // 暗含的意思是从目的地那个位置开始至少要保证可接受元素的大小是要copy的第一个序列的元素大小
    // 采用back_inserter函数是返回一个插入迭代器，赋值会调用容器内部的push_back
//    copy(lst.cbegin(),lst.cend(),vec.begin());
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    for (const auto &v : vec) {
        cout << v << endl;
    }

    vector<int> v_int;
    v_int.reserve(10);
    // 与前一个示例类似，算法并不改变容器的大小，虽然用reserve函数声明了容器能够保存10个元素的大小，
    // 但是实际上容器内部仍然为空，如果直接调用begin来填充数据仍然会出错
//    fill_n(v_int.begin(),10,0);
    fill_n(back_inserter(v_int), 10, 0);
    cout << "填充后容器元素为：" << endl;
    for (const auto &v: v_int) {
        cout << v << endl;
    }

    replace(v_int.begin(), v_int.end(), 0, 12);
    cout << "替换后容器元素为：" << endl;
    for (const auto &v: v_int) {
        cout << v << endl;
    }
    list<double> l_int_copy;
    // v_int_copy是空的容器，同时算法不能直接修改容器大小或者容器元素，不能在copy目的处使用其迭代器
    // replace_copy会将替换后的容器拷贝到新的容器中,拷贝的容器类型及元素类型不需要一样，只要元素能相互转换即可
//    replace_copy(v_int.begin(),v_int.end(),l_int_copy.begin(),12,24);
    replace_copy(v_int.cbegin(), v_int.cend(), back_inserter(l_int_copy), 12, 24);

    cout << "替换拷贝后原容器元素为：" << endl;
    for (const auto &v: v_int) {
        cout << v << endl;
    }
    cout << "替换拷贝后新容器元素为：" << endl;
    for (const auto &v: l_int_copy) {
        cout << v << endl;
    }

    return 0;
}


