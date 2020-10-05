//
// Created by KK on 2020/9/26.
//

#ifndef C___PRIMER_EXERCISE_9_52_H
#define C___PRIMER_EXERCISE_9_52_H

#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <utility>

class Operate {
public:
    virtual std::string baseOperate(const std::string &arg1, std::string &arg2) = 0;
};

class OperateAdd : public Operate {
public:
    std::string baseOperate(const std::string &arg1, std::string &arg2) override {
        return std::to_string(stold(arg1) + stold(arg2));
    }
};

class OperateSub : public Operate {
public:
    std::string baseOperate(const std::string &arg1, std::string &arg2) override {
        return std::to_string(stold(arg1) - stold(arg2));
    }
};

class OperateMultiply : public Operate {
public:
    std::string baseOperate(const std::string &arg1, std::string &arg2) override {
        return std::to_string(stold(arg1) * stold(arg2));
    }
};

class OperateDivide : public Operate {
public:
    std::string baseOperate(const std::string &arg1, std::string &arg2) override {
        return std::to_string(stold(arg1) / stold(arg2));
    }
};

class OperateRemainder : public Operate {
public:
    std::string baseOperate(const std::string &arg1, std::string &arg2) override {
        return std::to_string(stoll(arg1) % stoll(arg2));
    }
};

class OperateRightShift : public Operate {
public:
    std::string baseOperate(const std::string &arg1, std::string &arg2) override {
        return std::to_string(stoll(arg1) >> stoll(arg2));
    }
};

class OperateLeftShift : public Operate {
public:
    std::string baseOperate(const std::string &arg1, std::string &arg2) override {
        return std::to_string(stoll(arg1) << stoll(arg2));
    }
};

class OperateType {
public:
    OperateType() = default;

    // 每次构造函数时把当前的操作符传递到类中，同时将全部运算符绑定到对应的对象上
    explicit OperateType(std::string op_type) : cur_type(std::move(op_type)) {
        registerOperateType("+", new OperateAdd);
        registerOperateType("-", new OperateSub);
        registerOperateType("*", new OperateMultiply);
        registerOperateType("/", new OperateDivide);
        registerOperateType("%", new OperateRemainder);
        registerOperateType(">>", new OperateRightShift);
        registerOperateType("<<", new OperateLeftShift);
    }

    Operate *getOperate() const {
        return mapTable.at(cur_type);
    }

private:
    void registerOperateType(const std::string &type_str, Operate *op) {
        mapTable.insert({type_str, op});
    }

    std::map<std::string, Operate *> mapTable;
    std::string cur_type;
};

#endif //C___PRIMER_EXERCISE_9_52_H
