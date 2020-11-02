/**
 * Exercise 12.1-12.2 编写自己的StrBlob类，包含const版本的的front和back
 * */
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <initializer_list>
#include "../common/header/StrBlob.h"
using namespace std;

int main(int argc, char **argv) {

    // b1进行值初始化,其引用计数为1
    StrBlob b1 = {"bb"};
    b1.useCount("b1");
    cout << endl;
    StrBlob b3 = b1;
    {
        // b1进行了一次赋值操作，新的b3与b1指向同一块区域，其引用计数加1，为2
        b1.useCount("b1");
        b3.useCount("b3");
        cout << endl;
        StrBlob b2 = {"a", "ab", "the"};
        // b2在声明的同时进行了值初始化,引用计数为1
        b2.useCount("b2");
        cout << endl;
        b1 = b2;
        // b2进行了一次赋值操作，其引用计数加1，为2
        // b1进行了一次赋值操作，b1指向新的区域b2，那么b1其原来指向的区域b3的引用计数就会减1，为1
        b1.useCount("b1");
        b2.useCount("b2");
        b3.useCount("b3");
        cout << endl;
        b2.push_back("cc");
    } // b2离开其作用域，对象自动销毁，引用计数减1，最终只有b1还持有控制权
    b1.useCount("b1");
    b3.useCount("b3");
    // b2在离开其作用域时对象就被销毁了，不能再通过b2获取其元素个数了
    // 但是由于b2和b1是shared_ptr，共享同一组数据,可以认为b2也包含同b1一样的元素个数
//    cout << b2.size() << endl;
    cout << b1.size() << endl;
    cout << b1.front() << endl;
    cout << b1.back() << endl;
    b1.pop_back();
    cout << b1.back() << endl;
    cout << b3.front() << " " << b3.back() << endl;


    return 0;
}


