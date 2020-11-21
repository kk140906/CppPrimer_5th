/**
 * @details: Exercise 18.18 已知swap的典型定义,当mem1是string对象时使用哪个版本，如果是int使用哪个版本
 *           template<typename T>
 *           void swap(T v1,T v2){
 *              using std::swap;
 *              swap(v1.mem1,v2.mem1);
 *           }
 * @details: Exercise 18.19 如果对swap的调用形式使用std::swap(v1.mem1,v2.mem2);
 */
#include <iostream>
#include <string>

/**
 * @brief 根据函数模板的实参对模板参数进行推断，在swap函数内部首先进行了swap的using声明，因此
 *        首先在swap函数模板的内部作用域中查找std::swap函数是否匹配当前的实参，不匹配则继续向实参的类型中查找。
 *        当参数是string类型的时候，会调用string的swap进行交换，当参数是int类型的时候，直接调用std::swap交换。
 * @tparam T
 * @param v1
 * @param v2
 */

template<typename T>
void swap(T &v1, T &v2) {
    using std::swap;
//    std::swap(v1.mem1, v2.mem1); // 该版本只能交换的标准库版本的swap可以交换的数据，自定义swap的数据就不能使用
    swap(v1.mem1, v2.mem1);
}

struct A {
    int mem1;
};

struct B {
    std::string mem1;
};

struct C {

    C(double d) : mem1(d) {}

    struct D {
        // 定义为delete，让标准库版本的swap不能移动数据
        D(D &&) noexcept = delete;

        friend void swap(D &lhs, D &rhs) {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            using std::swap;
            swap(lhs.data, rhs.data);
        }

        friend std::ostream &operator<<(std::ostream &os, const D &rhs) {
            return os << rhs.data;

        }

        D(double d) : data(d) {}

    private:
        double data;

    };


    D mem1;
};

int main() {
    A a1, a2;
    a1.mem1 = 42;
    a2.mem1 = 5;
    // 使用标准库的swap
    swap(a1, a2);
    std::cout << a1.mem1 << " " << a2.mem1 << std::endl;
    B b1, b2;
    b1.mem1 = "hello";
    b2.mem1 = "world";
    // 使用string的swap;
    swap(b1, b2);
    std::cout << b1.mem1 << " " << b2.mem1 << std::endl;
    C c1{3.14}, c2{5.68};
    swap(c1, c2);
    std::cout << c1.mem1 << " " << c2.mem1 << std::endl;

}

