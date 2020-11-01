/*
 * Exercise 15.35 实现Query类和QueryBase类
 * Exercise 15.36 在构造函数和rep成员中添加打印语句，Exercise15.34中的(a),(b)输出
 * Exercise 15.39
 */


#include <iostream>
#include "../common/header/query_base.h"

using namespace std;


int main() {
    string file("Pride_And_Prejudice.txt");
    TextQuery tq(file);
    Query q = Query("this") & Query("once") | Query("men");
    cout << q << endl;
    TextQueryResult result = q.eval(tq);
    result.print();
    return 0;
}

