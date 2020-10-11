/*
 * Exercise 12.14 编写你自己版本的shared_ptr管理connection的函数
 * Exercise 12.15 编写你自己版本的shared_ptr管理connection的函数,使用lambda替换doDisconnect函数
 * */
#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct destination {
    string ip;
    int port;

    destination() = default;

    destination(const string c_ip, const int c_port) : ip(c_ip), port(c_port) {}
};

struct connection {
    string ip;
    int port;

    connection() = default;

    connection(const string c_ip, const int c_port) : ip(c_ip), port(c_port) {}
};

connection doConnect(const destination *dest) {
    cout << "开始连接 - " << dest->ip << ":" << dest->port << endl;
    // 使用new显式创建一个指向connection结构体的指针，利用这个指针去初始化shared_ptr,
    // 将控制权限交给ptr后，会delete该结构体指针
//    shared_ptr<connection> ptr(new connection);
    // make_shared的初始化参数必须要求参数是可以转换成connection对象
    auto ptr = make_shared<connection>(connection(dest->ip, dest->port));
    cout << __func__ << " - shared_ptr 使用计数:" << ptr.use_count() << endl;
//    return *ptr;
    // 不使用shared_ptr时,使用new创建的connection对象会在程序结束前一直存在
    auto common_ptr = new connection;
    common_ptr->ip = dest->ip;
    common_ptr->port = dest->port;
    return *common_ptr;
} // ptr在退出时引用计数就减少为0了
connection doConnect(const destination *dest, const string &str) {
    cout << str << "开始连接 - " << dest->ip << ":" << dest->port << endl;
    // 使用new显式创建一个指向connection结构体的指针，利用这个指针去初始化shared_ptr,
    // 将控制权限交给ptr后，会delete该结构体指针
//    shared_ptr<connection> ptr(new connection);
    // make_shared的初始化参数必须要求参数是可以转换成connection对象
    auto ptr = make_shared<connection>(connection());
    cout << str << __func__ << " - shared_ptr 使用计数:" << ptr.use_count() << endl;
//    return *ptr;
    // 不使用shared_ptr时,使用new创建的connection对象会在程序结束前一直存在
    auto common_ptr = new connection;
    common_ptr->ip = dest->ip;
    common_ptr->port = dest->port;
    return *common_ptr;
} // ptr在退出时引用计数就减少为0了

// 注意doDisconnect函数接受的参数是const指针形式,
// 这是为了让shared_ptr在初始化时将接受的指针实参顺利传输到函数内部
void doDisconnect(const connection *connect) {
    cout << "断开连接 - " << connect->ip << ":" << connect->port << endl;
}


int main(int argc, char **argv) {
    auto dest = new destination;
    dest->ip = "10.0.0.110";
    dest->port = 2699;
    connection con = doConnect(dest);

    // 创建shared_ptr，使用创建的connection对象的地址进行初始化,ptr_con引用计数1,
    // ptr_con2由于仅声明未定义,引用计数仍然为0;
    // ptr_con3利用new显式创建一个结构体指针来初始化为shared_ptr,引用计数为1
    // 此处ptr_con的初始化必须指定一个自定义的删除器，
    // 因为只接受一个参数的shared_ptr<connection> p(q)中的初始化参数q必须由new创建，因为该初始化过程会调用delete q
    // 而con是doConnect函数返回值初始化的局部对象，无法通过delete释放内存区域
    // 如果仍然想调用一个参数的shared_ptr,可以将doConnect函数的返回值声明为指针,而不是connection对象
    shared_ptr<connection> ptr_con(&con, doDisconnect), ptr_con2, ptr_con3(new connection);
    cout << __func__ << " - ptr_con shared_ptr 使用计数:" << ptr_con.use_count() << endl;
    cout << __func__ << " - ptr_con2 shared_ptr 使用计数:" << ptr_con2.use_count() << endl;
    cout << __func__ << " - ptr_con3 shared_ptr 使用计数:" << ptr_con3.use_count() << endl;
    cout << endl;
    // 进行一次赋值操作,ptr_con的引用计数加1,ptr_con2与ptr_con指向同一块区域，引用计数均为2
    // ptr_con3未做操作，引用计数仍为1
    ptr_con2 = ptr_con;
    cout << __func__ << " - ptr_con shared_ptr 使用计数:" << ptr_con.use_count() << endl;
    cout << __func__ << " - ptr_con2 shared_ptr 使用计数:" << ptr_con2.use_count() << endl;
    cout << __func__ << " - ptr_con3 shared_ptr 使用计数:" << ptr_con3.use_count() << endl;
    cout << endl;
    // ptr_con2 进行一次赋值操作,ptr_con2原来指向的区域引用计数减1，最终就只剩下ptr_con指向原来区域了
    // 而ptr_con3拷贝到ptr_con2,引用计数加1,此时ptr_con2和ptr_con3指向同一块区域，引用计数均为2;
    ptr_con2 = ptr_con3;
    cout << __func__ << " - ptr_con shared_ptr 使用计数:" << ptr_con.use_count() << endl;
    cout << __func__ << " - ptr_con2 shared_ptr 使用计数:" << ptr_con2.use_count() << endl;
    cout << __func__ << " - ptr_con3 shared_ptr 使用计数:" << ptr_con3.use_count() << endl;
    // shared_ptr离开其作用域时会销毁其所有对象

    auto test_lambda = true;
    cout << endl;
    if (test_lambda) {
        cout << string(5, ' ') << "lambda test start:" << endl;
        dest->ip = "192.168.1.21";
        dest->port = 3306;
        connection con_lambda = doConnect(dest, string(5, ' '));
        shared_ptr<connection> ptr_con_lambda(&con_lambda, [](const auto &cc) {
            cout << string(5, ' ') << "断开连接 - " << cc->ip << ":" << cc->port << endl;
        });
    } // ptr_con_lambda离开作用域自动销毁其对象区域
    cout << string(5, ' ') << "lambda test end." << endl;
    cout << endl;
    return 0;
}// ptr_con,ptr_con2,ptr_con3均是该作用域内，shared_ptr离开其作用域引用计数减一，
// 最终引用计数为0时自动销毁shared_ptr及其指向的对象或者内存区域


