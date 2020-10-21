/*
 * Exercise 13.27 定义使用引用计数版本的HasPtr,
 * */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr {

public:

    HasPtr() : ps(new std::string), i(0), use(new std::size_t(1)) {}

    HasPtr(const string &str, const int ii) : ps(new std::string(str)), i(ii), use(new std::size_t(1)) {}

    // 拷贝构造函数
    HasPtr(const HasPtr &right) : ps(right.ps), i(right.i) {
        ++*right.use;
        use = right.use;
    }

    // 拷贝赋值运算符
    HasPtr &operator=(const HasPtr &right) {
        ++*right.use;
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        use = right.use;
        ps = right.ps;
        i = right.i;
        return *this;
    }

    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }

    void print() {
        std::cout << *ps << std::endl;
        std::cout << i << std::endl;
    }

    std::size_t use_count() { return *use; }

private:
    std::size_t *use;
    std::string *ps;
    int i;
};

int main(int argc, char **argv) {
    HasPtr p1("hello", 10), p2;
    std::cout << "引用计数: " << p1.use_count() << " " << p2.use_count() << std::endl;
    // 调用拷贝赋值运算符
    p2 = p1;
    std::cout << "引用计数: " << p1.use_count() << " " << p2.use_count() << std::endl;
    // 调用拷贝赋值运算符
    // 调用拷贝构造函数，注意与拷贝赋值运算符区分
    // 在对象定义时的 ”=“ 是调用拷贝构造函数,不是调用拷贝赋值运算符
    HasPtr p3 = p1;
    std::cout << "引用计数: " << p1.use_count() << " " << p2.use_count() << " " << p3.use_count() << std::endl;
    return 0;
} // 三个对象在离开时会调用各自的析构函数


