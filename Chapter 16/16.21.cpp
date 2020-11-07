/**
 * @details : Exercise 16.21 编写自己版本的DebugDelete版本
 * @details : Exercise 16.22 在TextQuery程序中使用DebugDelete作为shared_ptr的删除器
 * @details : Exercise 16.23 测试什么时候会调用DebugDelete运算符
 */


#define Exercise1622

#include <iostream>
#include <string>
#include <vector>

#include "../common/header/debug_delete.h"
#include "../common/header/text_query.h"
#include "../common/header/text_query_result.h"
#include "../common/header/query_base.h"

using namespace std;

int main() {

    int *p = new int(10);
    DebugDelete d;
    d(p);


    string file("Pride_And_Prejudice.txt");
    TextQuery q(file);
    q.query("hello");


    return 0;
}

