/*
 * Exercise 9.23 当容器大小为1时，其begin(),front(),end(),back()对应的值是什么
 * 9.24 分别使用at，下标，front和begin分别提取vector中的第一个元素，然后在一个空的vector中进行测试
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    vector<int> v_int{2};
    // begin,end返回的是容器的迭代器
    // front,back返回的是容器内元素的引用
    auto val1 = v_int.begin();
    auto val2 = v_int.front();
    // 尾后迭代器不能用于解引用操作，属于非法操作
    auto val3 = --v_int.end();
    auto val4 = v_int.back();
    cout << "vector的元素内容为:" << endl;
    cout << *val1 << "\t" << val2 << "\t" << *val3 << "\t" << val4 << endl;

    vector<int> v_int2;
    // 下标越界
    cout << v_int2[0] << endl;
    cout << v_int2.front() << endl;
    cout << *v_int2.begin() << endl;
    // 下标不合法时,at会抛出异常
    cout << v_int2.at(0) << endl;
    return 0;
}


