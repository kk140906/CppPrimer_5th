/*
 * Exercise 12.6 编写函数，返回一个动态分配的int的vector,
 * 将此vector传递给另外一个函数，这个函数读取标准输入，将读入的值保存在vector元素中
 * 再将vector传递给另外一个函数，打印读入的值，记得在恰当的时候delete vector
 * */
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

using vector_ptr = vector<int> *;

vector_ptr allocElement() {
    return new vector<int>();
}

void readElement(vector_ptr &ptr) {
    int i;
    cout << "请输入一系列数值:" << endl;
    while (cin >> i) {
        ptr->push_back(i);
    }
}


void printElement(const vector_ptr &ptr) {
    cout << "输入数值为:" << endl;
    for (const auto &ce : *ptr) {
        cout << ce << " ";
    }
}

int main(int argc, char **argv) {

    auto ptr = allocElement();
    readElement(ptr);
    printElement(ptr);
    delete ptr;
    ptr = nullptr;
    return 0;
}


