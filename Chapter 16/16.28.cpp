/**
 * @details : Exercise 16.28 编写自己版本的shared_ptr和unique_ptr
 * @details : Exercise 16.38 make_shared提供显式模板实参
 * @details : Exercise 16.61 定义自己版本的make_shared
 */


#define Exercise1622

#include <iostream>
#include <string>
#include <vector>

#include "../common/header/shared_ptr.h"
#include "../common/header/unique_ptr.h"
#include "../common/header/debug_delete.h"


using namespace std;

int main() {

    SharedPtr<int> sp_i1(5), sp_i2(sp_i1);
    cout << sp_i1.UseCount() << " " << sp_i2.UseCount() << endl;
    cout << *sp_i1 << " " << *sp_i2 << endl;
    sp_i1.reset(new int(10), DebugDelete());
    cout << sp_i1.UseCount() << " " << sp_i2.UseCount() << endl;
    cout << *sp_i1 << " " << *sp_i2 << endl;
    // 显式指定make_shared的模板实参，可以根据期望指向的对象进行期望的类型转换
    auto sp_d = make_shared<int>(6.6);
    cout << sp_d.UseCount() << " " << *sp_d << endl;

    UniquePtr<int> up_il1(new int(5));
    cout << *up_il1 << " " << *up_il1.release() << endl;

    up_il1.reset(nullptr);

    return 0;
}

