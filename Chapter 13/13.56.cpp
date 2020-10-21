/*
 * Exercise 13.56 如果sorted定义如下，会发生什么
 * Foo Foo::sorted() const &{
 *      Foo ret(*this);
 *      ret.sorted();
 *      return ret;
 * }
 *
 * Exercise 13.57 如果sorted定义如下，会发生什么
 * Foo Foo::sorted() const &{ return Foo(*this).sorted(); }
 *
 * Exercise 13.58,验证前面两个答案
 */

#include <iostream>
#include <algorithm>
#include <vector>

class Foo {
public:
    void push_back(int i) { data.push_back(i); }

    Foo sorted() &&{
        std::cout << "右值引用版本" << std::endl;
        std::sort(data.begin(), data.end());
        return *this;
    }

    Foo sorted() const &{
        std::cout << "左值引用版本" << std::endl;

#define Exercise1357

#ifdef Exercise1356
        Foo ret(*this);
        // 如果直接调用sorted函数会发生死递归，ret是左值，会接着递归调用本函数
        ret.sorted();
        return ret;
// #elif 需要一个表达式，而不是值，类似于#if
#elif defined(Exercise1357)
        // 如果调用这个返回，那么Foo(*this)会创建一个临时对象，然后调用右值才能使用的sorted排序
        // 这种方式可以避免对象的拷贝
        return Foo(*this).sorted();
#else
        Foo ret(*this);
        std::sort(ret.data.begin(), ret.data.end());
        return ret;
#endif
    }

    void print() {
        for (const auto &d:data) {
            std::cout << d << " ";
        }
    }

private:
    std::vector<int> data;
};


using namespace std;

int main(int argc, char **argv) {

    Foo f;
    f.push_back(6);
    f.push_back(1);
    f.push_back(3);
    f.push_back(9);
    auto tmp = f.sorted();
    tmp.print();

    return 0;
}



