/*
 * Exercise 13.14 假定numbered是一个类，它有一个默认构造函数，能为每个对象生成一个唯一的序号，保存在名为mysn的数据成员中，
 * 当numbered使用合成的拷贝控制成员时，并创建以下函数调用
 * void func(numbered s) { cout << s.mysn << endl;}
 * 那么下面代码输出的内容是什么
 * numbered a, b = a, c = b;
 * func(a); func(b); func(c);
 * Exercise 13.15 如果numbered定义了一个拷贝构造函数，能够生成一个新的序号，那么Exercise 13.14的输出结果又是什么
 * Exercise 13.16 如果func中的参数是const numbered & ,那么Exercise 13.14的输出结果又是什么
 * Exercise 13.17 验证上述结果
 */

#include <iostream>


using namespace std;

namespace Exercise1314 {
    // 利用全局变量实现简单的唯一序列特性
    std::size_t uid = 0;

    class numbered {
    public:
        numbered() { mysn = uid++; }

        std::size_t mysn;
    };

    void func(numbered s) { std::cout << s.mysn << std::endl; }
}

namespace Exercise1315 {
    // 利用全局变量实现简单的唯一序列特性
    std::size_t uid = 0;

    class numbered {
    public:
        numbered() { mysn = uid++; }

        numbered(numbered &) { mysn = uid++; }

        std::size_t mysn;
    };

    void func(numbered s) { std::cout << s.mysn << std::endl; }
}
namespace Exercise1316 {
    // 利用全局变量实现简单的唯一序列特性
    std::size_t uid = 0;

    class numbered {
    public:
        numbered() { mysn = uid++; }

        numbered(numbered &) { mysn = uid++; }

        std::size_t mysn;
    };

    void func(const numbered &s) { std::cout << s.mysn << std::endl; }
}

int main(int argc, char **argv) {
    std::cout << "Exercise13.14:" << std::endl;
    Exercise1314::numbered a, b = a, c = b;
    Exercise1314::func(a);
    Exercise1314::func(b);
    Exercise1314::func(c);
    std::cout << "Exercise13.15:" << std::endl;
    Exercise1315::numbered x, y = x, z = y;
    Exercise1315::func(x);
    Exercise1315::func(y);
    Exercise1315::func(z);
    std::cout << "Exercise13.16:" << std::endl;
    Exercise1316::numbered l, m = l, n = m;
    Exercise1316::func(l);
    Exercise1316::func(m);
    Exercise1316::func(n);
    return 0;
}


