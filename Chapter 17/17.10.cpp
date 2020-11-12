/**
 * @details: Exercise 17.10 使用序列1,2,3,5,8,13,21初始化一个bitset，将这些位置置位。
 * @details: 对另一个bitset执行默认初始化,并编写一小段程序将其恰当的位置位
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <bitset>


using namespace std;

int main() {
    unsigned u = (1 << 21) | (1 << 13) | (1 << 8) | (1 << 5) | (1 << 3) | (1 << 2) | (1 << 1);
    bitset<32> bit_vec1(u);
    cout << bit_vec1 << endl;

    bitset<32> bit_vec2;
    bit_vec2.set(1).set(2).set(3).set(5).set(8).set(13).set(21);
    cout << bit_vec2 << endl;
    return 0;
}

