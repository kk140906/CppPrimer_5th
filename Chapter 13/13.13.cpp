/*
 * Exercise 13.13 给类
 * struct X {
 *      X() {std::cout << "X()" << std::endl;}
 *      X(const X&) {std::cout << "X(const X&)" << std::endl;}
 * };
 * 添加拷贝赋值运算符和析构函数，并编写一个程序以不同的方式使用X的对象
 * 将它们做为非引用和引用参数进行传递
 * 动态分配它们
 * 将它们存放在容器中
 * */
#include <iostream>
#include <vector>

using namespace std;


// struct默认为public成员
struct X {
    // 构造函数
    X() { std::cout << "X()" << std::endl; }

    // 构造函数
    X(const X *x) { std::cout << "X(const X *x)" << std::endl; }

    // 拷贝构造函数
    X(const X &x) { std::cout << "X(const X &x)" << std::endl; }

    // 拷贝赋值运算符
    X &operator=(const X &) {
        std::cout << "X &operator=(const X &)" << std::endl;
        return *this;
    }

    // 析构函数
    ~X() { std::cout << "~X()" << std::endl; }
};

void funcNoReference(X x) {
    std::cout << __func__ << std::endl;
}

void funcReference(X &x) {
    std::cout << __func__ << std::endl;
}

int main(int argc, char **argv) {

    std::cout << "定义对象x1:" << std::endl;
    // 创建对象会调用X的构造函数
    X x1;
    std::cout << std::endl;

    std::cout << "调用函数funcNoReference:" << std::endl;
    // 作为非引用对象函数参数，会调用拷贝构造函数,函数调用结束后调用析构函数销毁临时对象
    funcNoReference(x1);
    std::cout << std::endl;

    std::cout << "定义对象x2:" << std::endl;
    // 创建对象会调用X的构造函数,如果是X x2 = x1；则利用对象x1初始化x2不会调用X的构造函数，而是调用X的拷贝构造函数
    X x2;
    std::cout << "调用函数funcReference:" << std::endl;
    // 作为引用对象的函数参数，不会调用拷贝构造函数,也不会调用析构函数销毁临时对象
    funcReference(x2);
    std::cout << std::endl;

    std::cout << "调用拷贝赋值运算符:" << std::endl;
    // 将一个对象赋值给另外一个同类型的对象会调用拷贝赋值运算符
    x2 = x1;
    std::cout << std::endl;

    std::cout << "动态创建对象:" << std::endl;
    // 动态创建对象，调用X的构造函数
    auto px3 = new X;
    std::cout << std::endl;

    vector<X> vec_X;

    std::cout << "将容器元素个数调整为2" << std::endl;
    // resize会执行元素的默认初始化，因此会调用两次构造函数
    vec_X.resize(2);
    std::cout << std::endl;

    std::cout << "将px3指向的对象push_back到vector容器中(拷贝初始化):" << std::endl;
    // 根据vector的内存调整策略，resize为2之后,其capacity和size都是2，
    // 当有新的元素添加的时候原来的vector会被拷贝到新的vector中,会导致原来vector的2个对象的调用拷贝构造函数
    // push_back insert之类的函数会新增加一次对新增对象的拷贝构造函数的调用次数
    // 新增完毕后将原来vector中的2个对象对象销毁会调用2次析构函数，最后销毁原来的vector对象
    vec_X.push_back(*px3);
    std::cout << std::endl;

    std::cout << "将px3指向的对象emplace_back到vector容器中(直接初始化):" << std::endl;
    // emplace_back是直接初始化调用的是与传递参数匹配的构造函数，编译器忽略其拷贝构造函数,
    // 当没有其匹配的构造函数时调用拷贝构造函数
//    vec_X.emplace_back(*px3);
    vec_X.emplace_back(px3);
    std::cout << std::endl;

    std::cout << "释放px3指向的内存:" << std::endl;
    // 销毁对象会调用X的析构函数
    delete px3;
    std::cout << "函数结束:" << std::endl;
    return 0;
}
// x1,x2,vecX中的4个对象离开作用域会调用X的析构函数
// 最后调用vector的析构函数

