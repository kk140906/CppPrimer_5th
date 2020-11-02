/**
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
    // 必须定义为指针类型，保证无论什么情况下有新的指针指向或者不指向这个对象的时候引用计数都能正确改变
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
    // 这个操作验证了为什么用于引用计数的类型必须是指针类型
    // 假设计数的类型不是指针类型，那么在前面两个操作后,p1,p2的引用计数都为2,如果此时再用p1进行了一次拷贝构造函数
    // 那么p1和p3的引用计数是能够正确更新的，但是p2的引用计数却无法更新，
    // 但是p1,p2,p3本质都是指向同一对象的指针，应该具有相同的引用计数
    // 与此同时，定义为指针后，拷贝构造函数和拷贝赋值运算符的形参就可以正常限制为const类型了，
    // 否则由于进行了指针的拷贝和赋值，引用计数需要正常更新，这就不能限制为const类型
    HasPtr p3 = p1;
    std::cout << "引用计数: " << p1.use_count() << " " << p2.use_count() << " " << p3.use_count() << std::endl;
    return 0;
} // 三个对象在离开时会调用各自的析构函数


