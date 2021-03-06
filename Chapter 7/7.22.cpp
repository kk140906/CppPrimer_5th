/**
 * Exercise 7.22  给Person类添加构造函数
 */
#include <iostream>
#include <string>

using namespace std;

struct Person {
    // 定义为友元函数之后能够访问内部的private成员
    friend istream &recordPersonInfo(istream &is, Person &person);

    friend ostream &showPersonInfo(ostream &os, const Person &person);

private:
    string name;
    string address;
public:
    string getName() const { return name; }

    string getAddress() const { return address; }

    Person() = default;

    Person(const string &name, const string &address) {
        this->name = name;
        this->address = address;
    };

    // 当构造函数只有一个参数时需要显示声明,避免意外的隐式转换
    explicit Person(const string &name) : name(name) {};

    // 类中具有recordPersonInfo的友元声明，因此可以直接调用
    explicit Person(istream &is) { recordPersonInfo(is, *this); }
};

istream &recordPersonInfo(istream &is, Person &person);

ostream &showPersonInfo(ostream &os, const Person &person);

int main() {
    std::cout << "Hello, World!" << std::endl;
    Person person("小强");
    showPersonInfo(cout, person);
    cout << endl;
    Person person1("小明", "北京");
    showPersonInfo(cout, person1);
    cout << endl;
    Person person2;
    recordPersonInfo(cin, person2);
    showPersonInfo(cout, person2);
    cout << endl;
    Person person3(cin);
    showPersonInfo(cout, person3);
    cout << endl;
    return 0;
}

istream &recordPersonInfo(istream &is, Person &person) {
    cout << "请输入需要的录入新的人员信息！" << endl;
    cout << "Name:" << " ";
    is >> person.name;
    cout << "Address:" << " ";
    is >> person.address;
    return is;
}

ostream &showPersonInfo(ostream &os, const Person &person) {
    os << "Name:" << person.name << " Address:" << person.address;
    return os;
}