/*
 * Exercise 13.44 编写strings类的简化版本，命名为Strings,
 * 你的类至少应包含一个默认构造函数和一个接受C风格字符串指针参数的构造函数，使用allocator为你的Strings类分配所需内存
 * Exercise 13.47 为Strings类的拷贝构造函数和拷贝赋值语句添加一条语句，在函数执行时打印对应的信息
 * Exercise 13.48 定义一个vector<Strings>,并在其上面多次调用push_back,观察String被拷贝了多少次
 * Exercise 13.49,为你的Strings类添加一个移动构造函数和移动赋值运算符
 * Exercise 13.50,测试13.48,观察什么时候避免拷贝
 */

#include "13.44.String.h"
#include <iterator>
#include <vector>

using namespace std;
using namespace Exercise1344;

int main(int argc, char **argv) {

    char a[] = "hello";
    Strings s1(a), s2;
    s2 = s1;
    ostream_iterator<char> os(cout);
    copy(s2.cbegin(), s2.cend(), os);

    cout << endl << "vector" << endl;
    vector<Strings> vs;
    // 以下测试中定义了移动构造函数，由于push_back在创建Strings的对象后拷贝到vector中时会优先调用移动构造函数
    cout << "----------------第一个元素---------------" << endl;
    // 第一个元素，创建Strings对象会调用接收C风格字符串指针的构造函数，
    // 由于push_back会将结果拷贝到vector中会调用一次拷贝构造函数
    vs.push_back("hello");
    cout << "----------------第二个元素---------------" << endl;
    // 第二个元素，创建Strings对象会调用接收C风格字符串指针的构造函数，
    // push_back在复制第二个元素到容器中时发现容器空间不足，进行了一次扩容操作，
    // 这会把容器之前的一个元素拷贝到新的内存空间中，调用了一次拷贝构造函数
    // 将第二个元素复制到新的内存空间中，调用了一次拷贝构造函数
    vs.push_back("world");
    cout << "----------------第三个元素---------------" << endl;
    // 第三个元素，创建Strings对象会调用接收C风格字符串指针的构造函数，
    // 第三个元素与第二个元素过程类似，只是在进行扩容后的源容器拷贝时拷贝了2个元素，因此调用了2次拷贝构造函数
    // 将第三个元素复制到新的内存空间中，调用了一次拷贝构造函数
    vs.push_back("hello");
    cout << "----------------第四个元素---------------" << endl;
    //
    // 第四个元素，创建Strings对象会调用接收C风格字符串指针的构造函数，
    // 不会进行扩容操作，直接将元素拷贝到容器中，会调用一次拷贝构造函数
    vs.push_back("today");
    cout << "----------------第五个元素---------------" << endl;
    // 第五个元素，创建Strings对象会调用接收C风格字符串指针的构造函数，
    // 第五个元素与第三个元素过程类似，只是在进行扩容后的源容器拷贝时拷贝了4个元素，因此调用了4次拷贝构造函数
    // 将第五个元素复制到新的内存空间中，调用了一次拷贝构造函数
    vs.push_back("hi");

    cout << "----------------第六个元素---------------" << endl;
    // 第六个元素是已经创建的Strings对象，无论是否定义移动构造函数都会调用拷贝构造函数，这是因为s1是个左值。
    vs.push_back(s1);
    cout << "----------------第七个元素---------------" << endl;
    // 第七个元素显式通过std::move进行移动，如果没有定义移动构造函数会调用拷贝构造函数，否则调用移动构造函数
    vs.push_back(std::move(s1));
    return 0;
}




