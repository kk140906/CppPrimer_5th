/*
 * Exercise 7.4 编写一个名为Person的类，使其表示人员的姓名和地址，使用string对象保存这些信息
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


int main() {
    std::cout << "Hello, World!" << std::endl;
    Person person1 = {"xiaohong", "changchun"};
    cout << "Name:" << person1.getName() << " Address:" << person1.getAddress() << endl;
    return 0;
}

