/*
 * Exercise 13.18 定义一个Employee类,它包含雇员的姓名和唯一的雇员证号,为这个类定义默认的构造函数，
 * 以及接受一个表示雇员姓名的string的构造函数，每个构造函数应该通过递增一个static数据成员来生成一个唯一的证号
 * Exercise 13.19 你的Employee类需要定义它自己的拷贝控制成员吗？
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
    Employee() { id = uid++; }

    Employee(const string &str) : name(str) { id = uid++; }

    // 针对Exercise 19，我认为是没有必要添加自己的拷贝控制成员函数的，
    // 因为从实际使用上说，将一个Employee对象赋值或者拷贝给另外一个对象是没有意义的
    // 因此需要禁止拷贝构造函数和拷贝赋值运算符，通过delete告诉编译器这两个成员函数是被删除的

    // 禁止通过拷贝构造函数执行初始化
    Employee(Employee &e) = delete;

    // 禁止通过拷贝赋值运算符赋值
    Employee &operator=(Employee &e) = delete;

    void print() { cout << name << ":" << id << endl; }

private:
    static size_t uid;
    string name;
    size_t id;
};

size_t Employee::uid = 0;


int main(int argc, char **argv) {
    Employee a = {"小明"};
    a.print();
    Employee b("小红");
    b.print();
    string name = "小李";
    // 如果类定义删除了的拷贝构造函数和拷贝赋值运算符，那么就不能向容器中添加对象；
//    vector<Employee> ve;
//    ve.emplace_back(name);

    return 0;
}


