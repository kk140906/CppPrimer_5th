/*
 * Exercise 9.11 写出6种创建和初始化vector对象的方法,每一种都给出一个实例
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char **argv) {
    // 默认构造函数
    vector<string> v_str1;
    // 使用列表进行初始化
    v_str1 = {"hello", "world"};
    // 拷贝v_str1进行构造
    vector<string> v_str2(v_str1);
    // 与上一行等价的拷贝构造方式
    v_str2 = v_str1;
    // 使用迭代器进行构造
    vector<string> v_str3(v_str1.cbegin(), v_str1.cend());
    // 构造包含10个元素的容器，每个元素使用"haha"进行初始化
    vector<string> v_str4(10, "haha");
    // 构造包含5个元素的容器，每个元素执行默认初始化
    vector<string> v_str5(5);
    // 使用列表进行初始化构造,与vector<int> vi{1,2,3,4,5};类似对列表进行拷贝后构造
    vector<int> vi({1, 2, 3, 4, 5});

    return 0;
}


