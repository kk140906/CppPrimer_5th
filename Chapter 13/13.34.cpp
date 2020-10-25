/*
 * Exercise 13.34-13.37 编写Messages和Folders，分别表示消息及消息目录。
 * 每个Messages对象可以保存在多个Folder中，但是任意给定的Message的内容只有一个副本。
 * 因此一条消息的内容被修改，则我们从它所在的任何目录中来浏览此消息时，都会看到改变后的内容。
 * 为了记录消息位于哪些目录中，每个消息都会保存以它所在的目录的指针的集合。
 * 同样的，每个目录中都保存一个它包含的消息的指针的集合。
 * 消息提供save和remove操作，来分别向一个给定的目录中添加或者删除一条消息。
 * 当拷贝一个消息时，副本和源对象是不同的对象，但是两个对象都出现在相同的目录中
 * 目录提供addMsg和rmMsg,分别向一个目录添加或者删除给定的消息
 * 当拷贝一个目录时，副本和源对象是不同的对象，但是两个对象都会出现在相同的消息中
 * */
#include "../common/header/Messages_Folders.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    cout << "-----------Messages 拷贝构造函数------------" << endl;
    Messages a("hello"), b(a), c;
    cout << "a:" << endl;
    a.print();
    cout << "b:" << endl;
    b.print();
    cout << "c:" << endl;
    c.print();
    cout << endl;
    cout << "-----------Messages 拷贝赋值运算符------------" << endl;
    c = b;
    cout << "c." << endl;
    c.print();
    cout << endl;

    c.change("world");
    Folders f1;
    f1.addMsg(&a);
    f1.addMsg(&b);
    f1.addMsg(&c);
    cout << "-----------Folders 拷贝构造函数------------" << endl;
    cout << "f1:" << endl;
    f1.print();
    cout << "f2:" << endl;
    Folders f2 = f1, f3;
    f2.print();
    cout << endl;

    cout << "-----------Folders 拷贝赋值运算符------------" << endl;
    f3 = f1;
    cout << "f3:" << endl;
    f3.print();


    cout << endl;

    cout << "-----------Messages remove------------" << endl;
    cout << "a:" << endl;
    a.remove(&f1);
    a.print();
    cout << "b:" << endl;
    b.remove(&f1);
    b.remove(&f2);
    b.remove(&f3);
    b.print();
    cout << endl;

    cout << "-----------Messages save------------" << endl;
    cout << "b:" << endl;
    b.save(&f3);
    b.print();
    cout << endl;

    cout << "-----------Folders addMsg------------" << endl;
    cout << "f1:" << endl;
    f1.print();
    b.change("This");
    cout << "b:" << endl;
    b.print();
    cout << "f1-add:" << endl;
    f1.addMsg(&b);
    f1.print();
    cout << "b-add:" << endl;
    b.print();
    cout << endl;


    cout << "-----------Folders rmMsg------------" << endl;
    cout << "f1:" << endl;
    f1.print();
    cout << "b:" << endl;
    b.print();
    cout << "f1-rm:" << endl;
    f1.rmMsg(&b);
    f1.print();
    cout << "b-rm:" << endl;
    b.print();
    cout << endl;


    cout << "-----------Messages swap------------" << endl;
    cout << "a:" << endl;
    a.print();
    cout << "b:" << endl;
    b.print();
    swap(a, b);
    cout << "swap-a:" << endl;
    a.print();
    cout << "swap-b:" << endl;
    b.print();
    cout << endl;


    cout << "-----------Folders swap------------" << endl;
    cout << "f1:" << endl;
    f1.print();
    cout << "f2:" << endl;
    f2.print();
    swap(f1, f2);
    cout << "swap-f1:" << endl;
    f1.print();
    cout << "swap-f2:" << endl;
    f2.print();
    cout << endl;


    cout << "-----------Messages change b------------" << endl;
    b.change("anime");
    cout << "f1:" << endl;
    f1.print();
    cout << "f2:" << endl;
    f2.print();
    cout << "f3:" << endl;
    f3.print();
    return 0;
}



