/*
 * Exercise 10.13 标准库有一个partition算法，
 * 它可以接受一个谓词，对容器内容进行划分，使谓词为true的值排在容器前半部分，而使谓词为false的值会排在容器后半部分，
 * 算法返回一个迭代器，指向最后一个使谓词为true的的元素之后的位置。
 * 编写一个函数，接受一个string，返回一个bool，指出string是否有5个或者更多的字符，使用此函数划分一个容器，并打印出长度大于等于5的元素
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isBiggerFive(const string &str) {
    return str.size() >= 5;
}

auto partitionString(vector<string> &v_str) {
    return partition(v_str.begin(), v_str.end(), isBiggerFive);
}

int main(int argc, char **argv) {
    vector<string> v_str{"hello,world", "run", "world", "aa", "aa", "and", "the", "vector", "forward_list"};
    auto end = partitionString(v_str);
    for (auto begin = v_str.begin(); begin != end; ++begin) {
        cout << *begin << endl;
    }
    return 0;
}


