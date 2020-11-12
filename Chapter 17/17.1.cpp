/**
 * @details:Exercise 17.1 定义一个保存三个int的tuple，并将其成员初始化为10,20,30
 * @details: Exercise 17.2 定义一个tuple，保存string,vector<string>,pair<string,int>
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main() {

    tuple<int, int, int> t1(10, 20, 30);
    tuple<string, vector<string>, pair<string, int>> t2;
    cout << tuple_size<decltype(t2)>::value << endl;
    return 0;
}

