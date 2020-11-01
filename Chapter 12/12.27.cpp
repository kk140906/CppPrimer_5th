/*
 * Exercise 12.27 编写自己版本的TextQuery类和TextQueryResult类
 * TextQuery类用于读取给定文件的内容，然后根据给定的字符串查询该字符串在给定文件中出现的次数及其对应行数
 * TextQueryResult类用于打印、获取查询的结果
 * */


#include <iostream>
#include "../common/header/text_query.h"
#include "../common/header/text_query_result.h"

using namespace std;

int main(int argc, char **argv) {

    string file("Pride_And_Prejudice.txt");
    TextQuery textQuery(file);
    auto result = textQuery.query("this");
    result.print();
    return 0;
}




