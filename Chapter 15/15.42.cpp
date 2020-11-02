/**
 * Exercise 15.42 从下面几个选项中选择一种，设计并实现它：
 * (a) 按句子查询单词
 * (b) 引入历史系统，用户可以按历史查询编号查阅之前的某个查询记录，并且可以增加其中内容或者将其与其他查询结合
 * (c) 允许用户对结果进行限制，例如显示查询结果在给定范围内所有行
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


//    result.print();
    cout << "-----------------------------------------------" << endl;
    auto logger = QueryHistoriesLogger::CreatInstance();
    logger->Print();
    q = *logger->GetQuery(1) & Query("one");
    auto result2 = q.eval(tq);
    result2.print();
    cout << q << endl;
    logger->Print();
    cout << "-------------------clear------------------" << endl;
    logger->Clear();
    logger->Print();
    return 0;
}

