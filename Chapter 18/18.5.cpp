/**
 * @details: Exercise 18.5 修改main函数，使其能够捕获标准库的任何异常类型
 *           处理代码应该首先打印异常相关的错误消息，然后调用abort终止程序
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    try {
        throw range_error("occurred range error.");
    }catch (const exception &e) {
        cout << e.what() << endl;
        abort();
    } catch (...) {
        cout << "range error." << endl;
        throw;
    }
}

