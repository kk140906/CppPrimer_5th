/**
 * @details: Exercise 17.11 定义一个数据结构，包含一个整型对象，记录一个包含10个问题的真/假测验的回答，如果100个问题需要做什么
 * @details: Exercise 17.12 使用前一题的数据结构，编写一个函数，更新测试结果，它接受一个问题编号和一个表示真/假的解答的值
 * @details: Exercise 17.13 编写要一个整型对象，包含正确答案，使用它来测试前两个练习的成绩
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <bitset>


using namespace std;

template<unsigned N>
struct Quiz {
    void Answer(unsigned num, bool result) {
        quiz_.set(num, result);
    }

    std::size_t Score(int solutions) {
        std::bitset<N> goals(quiz_.to_ulong() & solutions);
        return goals.count();
    }

private:
    std::bitset<N> quiz_;
};

int main() {
    Quiz<10> q;
    q.Answer(1, 1);
    q.Answer(3, 1);
    q.Answer(5, 1);
    q.Answer(7, 1);
    q.Answer(8, 1);
    q.Answer(9, 1);

    int solution = 0b1010110111;
    cout << q.Score(solution);

    return 0;
}

