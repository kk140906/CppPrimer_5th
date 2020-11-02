/**
 * Exercise 10.6 用fill_n函数将一个序列中的int值都变为0
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main(int argc, char **argv) {
    vector<int> v_int{2, 3, 65, 5, 2, 5, 6, 2, 3, 4};
    fill_n(v_int.begin(), v_int.size(), 0);
    for (const auto &v : v_int) {
        cout << v << endl;
    }

    return 0;
}


