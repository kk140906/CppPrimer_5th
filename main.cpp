
#include <iostream>
#include <algorithm>

// 定义一个类Ptr
class Ptr {
public:
    static int a;

    Ptr *operator->() {
        std::cout << "调用重载函数operator->()" << std::endl;
        return this;
    }
};

// 假设类Ptr是最内层的一个类，在主函数定义一个Ptr对象去访问类中静态成员对象a
int Ptr::a = 10;


// 重载的->等价于函数调用
// 那么对于p1->a实际等价于(p1.operator->())->a;
// 先执行调用重载函数p1.operator->()，其返回的结果为对象的指针ret,
// 根据其递归终止条件，然后会调用内置的箭头运算符,解引用重载函数的返回结果ret，然后获取其成员对象a

using namespace std;

int main() {
    Ptr p1;
// 重载的->等价于函数调用
// 那么对于p1->a实际等价于(p1.operator->())->a;
// a位于Ptr内部，
    std::cout << p1->a << std::endl;

    return 0;
}
