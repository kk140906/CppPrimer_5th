/*
 * Exercise 9.52 使用stack处理括号化的表达式，当你看到一个左括号，将其记录下来。
 * 当在一个左括号之后看到一个右括号，从stack中pop对象，直到遇到左括号，将左括号也一起弹出栈
 * 然后将一个值(括号内的运算结果)push到栈中，此时表示一个括号化的表达式处理完毕
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "9.52.h"

using namespace std;

bool isNumber(const string &str) {
    return str.find_first_of("0123456789.") != string::npos;
}

void deleteSpace(string &str) {
    string::size_type pos = 0;
    while ((pos = str.find(' ', pos)) != string::npos) {
        str.erase(pos, 1);
    }
}

auto getExprSubString(string &str) {
    deleteSpace(str);
    string number("0123456789.");
    vector<string> vs;
    string::size_type pos = 0, end;
    while ((end = str.find_first_not_of(number, pos)) != string::npos) {
        if (pos != end) {
            vs.push_back(str.substr(pos, end - pos));
        }
        if (str[end] == '>' || str[end] == '<') {
            vs.push_back(str.substr(end, 2));
            pos = end, pos += 2;
        } else {
            vs.push_back(str.substr(end, 1));
            pos = end, ++pos;
        }
    }
    if (pos < str.size()) {
        vs.push_back(str.substr(pos));
    }
    return vs;
}


// 由于栈只能在栈顶进行操作，先出现的值会出现在栈底。
// 因此，一个表达式进入到栈是按照表达式从左至右的顺序，而出栈却是从右至左的，
// 如果表达式优先级相同，那么应当从左至右进行运算，这与栈的出栈顺序正好相反，
// 因此需要在恰当的时候进行栈元素的翻转操作，保证运算结果的正确性
stack<string> reverseStack(stack<string> src) {
    stack<string> result;
    while (!src.empty()) {
        result.push(src.top());
        src.pop();
    }
    return result;
}

// 根据不同的运算符确定执行的最基本的运算操作
string baseOperate(stack<string> &src) {
    string arg1, operate, arg2;
    // 获取第一个参与计算的操作数,随后将其出栈
    arg1 = src.top();
    src.pop();
    // 获取操作符后将操作符出栈
    operate = src.top();
    src.pop();
    // 获取第二个参数计算的操作数，随后将其出栈，清空整个栈
    arg2 = src.top();
    src.pop();
    // 根据操作符进行相应的计算
    OperateType op(operate);
    //形参决定了栈src的元素应该如何入栈
    auto result = op.getOperate()->baseOperate(arg1, arg2);
    return result;
}

// 逐次降低运算优先级，主要分三个等级，先 * / % 后 + - 最后 >> <<
stack<string> reduceOperateLevel(stack<string> &src, const int &level) {
    stack<string> lowLevelOperate, tmp;
    vector<string> op_level;
    if (level == 1) {
        op_level.emplace_back("*");
        op_level.emplace_back("/");
        op_level.emplace_back("%");
    } else if (level == 2) {
        op_level.emplace_back("+");
        op_level.emplace_back("-");
        op_level.emplace_back("");
    } else if (level == 3) {
        op_level.emplace_back(">>");
        op_level.emplace_back("<<");
        op_level.emplace_back("");
    }
    // src栈是一直被消耗的，栈空则该次计算完毕
    while (!src.empty()) {
        // 获取栈顶元素，根据该元素决定具体操作
        auto arg1 = src.top();
        //降低运算优先级的栈中是不可能出现左括号或者右括号的
        if (arg1 == "(") {
            throw invalid_argument("括号不匹配,缺少右括号!");
        }
        // 栈顶为运算符时
        if (arg1 == op_level[0] || arg1 == op_level[1] || arg1 == op_level[2]) {
            // 将运算符出栈
            src.pop();
            // 再次获取栈顶元素
            auto arg2 = src.top();
            // 将栈顶元素出栈
            src.pop();
            // 针对表达式以负数开始计算的特殊情况
            if (lowLevelOperate.empty() && arg1 == "-" && isNumber(arg2)) {
                tmp.push(arg2);
                tmp.push(arg1);
                tmp.push("0");
                //所有运算符都是二元运算符，不符合这样的情况表明输入的表达式不正确
            } else if (!isNumber(arg1) && isNumber(arg2) && isNumber(lowLevelOperate.top())) {
                tmp.push(arg2);
                tmp.push(arg1);
                tmp.push(lowLevelOperate.top());
                lowLevelOperate.pop();
            } else {
                string error_info(arg1);
                //TODO:错误信息不准确
                error_info.append(" 不是合法的运算符;或者").append(arg2).append(" 不是合法的操作数!\n");
                throw invalid_argument(error_info);
            }
            // 将计算的结果压入栈中以便下一次使用
            lowLevelOperate.push(baseOperate(tmp));
        } else {
            lowLevelOperate.push(arg1);
            src.pop();
        }
    }
    // 注意将栈翻转
    return reverseStack(lowLevelOperate);
}

// 计算非括号内的表达式的值
string calcExprNoBracket(stack<string> &src) {
    for (auto i = 1; i <= 3; ++i) {
        src = reduceOperateLevel(src, i);
    }
    return src.top();
}

// 计算整体表达式的值
auto calcExprWhole(vector<string> &vs) {
    stack<string> st, tmp;
    try {
        // 拆分的字符串全部压入栈中
        for (const auto &v : vs) {
            if (v != ")") {
                st.push(v);
            } else {
                // 找到右括号的情况
                auto top = st.top();
                while ((top = st.top()) != "(") {
                    st.pop();
                    // 如果栈空了也没找到左括号，说明缺少左括号
                    if (st.empty()) {
                        throw invalid_argument("括号不匹配,缺少左括号!");
                    }
                    tmp.push(top);
                }
                // 将左括号弹出
                st.pop();
                // 如果右括号左侧紧跟一个左括号，则直接弹出后进行下一次运算
                if (!tmp.empty()) {
                    st.push(calcExprNoBracket(tmp));
                }
            }
        }
        // 循环完了还有括号，则栈中一定是左括号，说明缺少右括号,可以在此之后再遍历一次整个栈判断是否存在括号
        // 为了方便，并且calcExprNoBracket函数也会每次都遍历传进去的栈，
        // 因此左括号的判定在其函数内部
        st = reverseStack(st);
        return calcExprNoBracket(st);
    }
    catch (invalid_argument &error) {
        cout << error.what() << endl;
    }
    return string("");
}

int main(int argc, char **argv) {
    stack<string> st;
    string expression("-6+ 2 3 / (1 0/ ((() 6)+2* 0.6) <<4 )%3");
//    expression = "5+10/2*0.5-4";
//    expression = "-6+2*0.6/5-9%2>>2";
//    expression = "(()6)";
    auto tmp = getExprSubString(expression);
    auto result = calcExprWhole(tmp);
    cout << result;
    return 0;
}