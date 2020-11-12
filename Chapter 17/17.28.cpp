/**
 * @details: Exercise 17.28 编写函数，每次调用生成并返回一个均匀的随机unsigned int
 * @details: Exercise 17.29 修改17.28的练习，允许用户提供一个种子作为可选参数
 * @details: Exercise 17.30 再修改17.29的练习，允许返回的最小值和最大值
 */
#include <iostream>

#include <random>

using namespace std;


void UniformDistribute(unsigned seed = 0) {
    default_random_engine e(seed);
    uniform_int_distribution<unsigned> ui(0, 100);
    for (int i = 0; i < 50; ++i) {
        cout << ui(e) << " ";
    }
    cout << endl;
}

void UniformDistribute(unsigned seed, std::size_t &min, std::size_t &max) {

    default_random_engine e(seed);
    uniform_int_distribution<unsigned> ui(0, 100);
    for (int i = 0; i < 50; ++i) {
        cout << ui(e) << " ";
    }
    cout << endl;
    min = ui.min();
    max = ui.max();
}


int main() {
    // 相同种子,生成的随机分布总是一样的
    UniformDistribute();
    UniformDistribute();
    UniformDistribute(10);
    std::size_t min, max;
    UniformDistribute(10, min, max);
    cout << "min: " << min << endl << "max: " << max << endl;
    return 0;
}

