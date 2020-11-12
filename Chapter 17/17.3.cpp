/**
 * @details: Exercise 17.3 使用tuple代替TextQueryResult类
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "../common/header/text_query.h"

using namespace std;

int main() {

    string file("Pride_And_Prejudice.txt");
    TextQuery tq(file);
    auto result = tq.query_return_tuple("this");

    cout << get<1>(result)->first << " occurs " << get<1>(result)->second.size() << " times." << endl;
    for (const auto &cq : get<1>(result)->second) {
        cout << "line " << cq + 1 << ": " << (*get<0>(result))[cq] << endl;
    }
    return 0;
}

