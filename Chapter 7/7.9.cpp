/**
 * Exercise 7.9  添加打印和读取Person对象的操作
 */
#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string address;

    string getName() const { return name; }

    string getAddress() const { return address; }
};

istream &recordPersonInfo(istream &is, Person &person);

ostream &showPersonInfo(ostream &os, const Person &person);

int main() {
    std::cout << "Hello, World!" << std::endl;
    Person person1 = {"小明", "北京"};
    showPersonInfo(cout, person1);
    cout << endl;
    Person person2;
    recordPersonInfo(cin, person2);
    showPersonInfo(cout, person2);
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