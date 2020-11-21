/**
 * @details: Exercise 18.6 已知下面的异常类型和catch语句，书写一个throw表达式使其创建的异常对象能被这些catch语句捕获
 */
#include <iostream>
#include <string>

using namespace std;

class exceptionType {
};

typedef int EXCPTYPE;

int main() {
    try {
//        throw new exceptionType();
//        throw EXCPTYPE(3);
        throw range_error("range_error");
    } catch (exceptionType *pet) {
        cout << "catch exceptionType by main." << endl;
    } catch (EXCPTYPE &i) {
        cout << i << "catch EXCPTYPE by main." << endl;
    } catch (...) {
        cout <<"catch all exception by main." << endl;
    }
}

