/**
 * Exercise 11.14 定义一个map，关键词是家庭的姓，值是一个vector,保存家中孩子的名，编写代码，实现添加新的家庭以及向已有家中添加新的孩子
 * 再添加一个pair的vector保存孩子的名和生日
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

    explicit FamilyCluster(map<string, vector<string>> &family) {
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

    void addMemberBirthday(const string &family_name, const string &member_name, const string &member_birthday) {
        if (!isContainFamilyMember(family_name, member_name)) {
            addMember(family_name, member_name);
        }
        familyMemberBirthday[family_name].emplace_back(pair<string, string>(member_name, member_birthday));
    }

    vector<string> getMember(const string &family_name) const {
        if (!isContainFamily(family_name))
            return vector<string>();
        // 此处无法使用[],只能使用at，因为该成员函数是常成员函数，如果familyMemberBirthday中不存在family_name,
        // 采用[]将会自动创建一个值初始化的以family_name为关键字的容器元素，
        // 这与常成员函数不能更改成员对象冲突，后几处采用at也是同样的原因
        // 由于at会检测参数合法性，确保在调用at前关键字应该已经存在
        return familyCluster.at(family_name);
    }

    string getMemberBirthday(const string &family_name, const string &member_name) const {
        if (!isContainFamilyMember(family_name, member_name)) {
            cout << family_name << "姓家庭中不存在家庭成员:" << member_name << endl;
            return null_str;
        }
        const auto memberBirthday = familyMemberBirthday.at(family_name);
        for (const auto &cm : memberBirthday) {
            if (cm.first == member_name) {
                return cm.second;
            }
        }
        return null_str;
    }

    bool isContainFamily(const string &family_name) const {
        return any_of(familyCluster.cbegin(), familyCluster.cend(),
                      [family_name](const auto &cf) { return cf.first == family_name; });
    }

    bool isContainFamilyMember(const string &family_name, const string &member_name) const {
        if (!isContainFamily(family_name)) {
            return false;
        }
        auto memberCluster = familyCluster.at(family_name);
        return any_of(memberCluster.cbegin(), memberCluster.cend(),
                      [member_name](const auto &cm) { return cm == member_name; });
    }

private:
    string null_str = string("");
    map<string, vector<string>> familyCluster;
    map<string, vector<pair<string, string>>> familyMemberBirthday;
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
    familyCluster.addMemberBirthday(family_wang, "4", "2019-10-05");
    cout << family_wang + "4的生日是:" << familyCluster.getMemberBirthday(family_wang, "4") << endl;
    cout << family_wang + "5的生日是:" << familyCluster.getMemberBirthday(family_wang, "5") << endl;
    return 0;
}


