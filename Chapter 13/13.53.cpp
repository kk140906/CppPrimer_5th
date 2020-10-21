/*
 * Exercise 13.53 为HasPtr类实现一个拷贝赋值运算和一个移动赋值运算符
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr {

public:
    HasPtr(const std::string &s = std::string(), const int ii = 0) : ps(new std::string(s)), i(ii) {}

    // 拷贝构造函数,赋值初始化
    HasPtr(const HasPtr &obj) : ps(new std::string(*obj.ps)), i(obj.i) { std::cout << "调用拷贝构造函数" << std::endl; }

    // 拷贝赋值运算符，避免与移动赋值运算符冲突，在函数体内部进行拷贝并交换
    HasPtr &operator=(const HasPtr &right) {
        auto tmp = right;
        std::cout << "调用拷贝赋值运算符" << std::endl;
        swap(*this, tmp);
        return *this;
    }

    // 移动构造函数
    HasPtr(HasPtr &&obj) noexcept: ps(obj.ps), i(obj.i) {
        std::cout << "调用移动构造函数" << std::endl;
        obj.ps = nullptr;
    }

    // 移动赋值运算符
    HasPtr &operator=(HasPtr &&rhp) noexcept {
        std::cout << "调用移动赋值运算符" << std::endl;
        if (this != &rhp) {
            // ps是动态分配的资源使用前先释放资源
            delete ps;
            ps = rhp.ps;
            i = rhp.i;
            // 移动后源对象不应该再操作，保证正常析构
            rhp.ps = nullptr;
        }
        return *this;
    }

    void swap(HasPtr &lhs, HasPtr &rhs) {
        using std::swap;
        std::cout << "调用swap函数" << std::endl;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
    }

    bool operator<(const HasPtr &right) const {
        return this->i < right.i;
    }

    ~HasPtr() {
        std::cout << "调用析构函数" << std::endl;
        // 释放动态创建的对象
        delete ps;
    }

    void print() const {
        std::cout << *ps << std::endl;
        std::cout << i << std::endl;
    }

private:
    std::string *ps;
    int i;
};

int main(int argc, char **argv) {
    HasPtr p1("hello", 10), p2;
    p2.print();
    // 调用拷贝赋值运算符
    p2 = p1;
    p2.print();
    // 调用拷贝构造函数，注意与拷贝赋值运算符区分
    // 在对象定义时的 ”=“ 是调用拷贝构造函数,不是调用拷贝赋值运算符
    HasPtr p3 = p1;
    p3.print();

    vector<HasPtr> vh;
    vh.emplace_back("hello", 20);
    vh.emplace_back("world", 9);
    vh.push_back(HasPtr("hello ", 40));
    vh.push_back(HasPtr("today", 15));
    cout << "-------------------------" << endl;
    sort(vh.begin(), vh.end());
    cout << "-------------------------" << endl;
    for_each(vh.begin(), vh.end(), [](const auto cvh) { cvh.print(); });

    return 0;
} // 三个对象在离开时会调用各自的析构函数


