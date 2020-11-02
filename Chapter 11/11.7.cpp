/**
 * Exercise 11.7 定义一个map，关键词是家庭的姓，值是一个vector,保存家中孩子的名，编写代码，实现添加新的家庭以及向已有家中添加新的孩子
 * */
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class FamilyCluster {
public:
    FamilyCluster() = default;

    explicit FamilyCluster(const string &family_name) {
        familyCluster[family_name];
    }

    explicit FamilyCluster(map<string, vector<string>> family) {
        for (const auto &f : family) {
            familyCluster[f.first] = f.second;
        }
    }

    // 添加family时不进行任何操作
    // 如果familyCluster内已经包含了添加的family_name则不会发生任何变化
    // 如果familyCluster内没有包含添加的family_name则会初始化一个空的家庭成员
    void addFamily(const string &family_name) {
        familyCluster[family_name];
    }

    // 添加家庭成员也不需要判断家庭名是否存在,如果不存在map会自动创建
    void addMember(const string &family_name, const string &member_name) {
        familyCluster[family_name].push_back(member_name);
    }

    void addMember(const string &family_name, const vector<string> &member_name) {
        familyCluster[family_name] = member_name;
    }

    vector<string> getMember(const string &family_name) {
        return familyCluster[family_name];
    }

    bool isContainFamily(const string &family_name) {
        return any_of(familyCluster.cbegin(), familyCluster.cend(),
                      [family_name](const auto &f) { return f.first == family_name; });
    }

private:
    map<string, vector<string>> familyCluster;
};

int main(int argc, char **argv) {

    map<string, vector<string>> zhao_family_members{{"赵", {"4", "6"}}};
    FamilyCluster familyCluster(zhao_family_members);
    string family_wang("王"), family_zhao("赵");
    if (familyCluster.isContainFamily(family_wang)) {
        cout << "家庭族中包含'王'姓家庭" << endl;
    } else {
        cout << "家庭族中不包含'王'姓家庭" << endl;
    }
    if (familyCluster.isContainFamily(family_zhao)) {
        cout << "家庭族中包含'赵'姓家庭" << endl;
    } else {
        cout << "家庭族中不包含'赵'姓家庭" << endl;
    }
    familyCluster.addFamily(family_wang);
    familyCluster.addMember(family_wang, vector<string>({"1", "2", "3", "4", "5"}));
    for (const auto &f : familyCluster.getMember(family_wang)) {
        cout << family_wang + f << ",";
    }
    cout << endl;
    familyCluster.addFamily(family_zhao);
    familyCluster.addMember(family_zhao, "2");
    for (const auto &f : familyCluster.getMember(family_zhao)) {
        cout << family_zhao + f << ",";
    }
    cout << endl;
    return 0;
}


