/**
 * Exercise 11.23 定义一个multimap，关键词是家庭的姓，值保存家中孩子的名，编写代码，实现添加新的家庭以及向已有家中添加新的孩子
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

    FamilyCluster(const string &family_name, const string &member_name) {
        addFamilyMember(family_name, member_name);
    }

    explicit FamilyCluster(const pair<string, string> &family) {
        addFamilyMember(family);
    }

    // 可重复的key，单独在添加一个空的family已经没有意义了，直接添加新的家庭成员即可
    void addFamilyMember(const string &family_name, const string &member_name) {
        if (isContainFamilyMember(family_name, member_name)) {
            return;
        }
        // multimap由于可以具有多个相同的key，
        // 因此[]运算符无法准确判定关键词为family_name的哪个值是期望的值
        // 此时应当采用insert方法实现family的添加
        familyCluster.insert({family_name, member_name});
        // 添加家庭成员时添加生日信息,默认为空
        familyMemberBirthday[{family_name, member_name}];
    }

    void addFamilyMember(const pair<string, string> &family) {
        if (isContainFamilyMember(family)) {
            return;
        }
        familyCluster.insert(family);
        familyMemberBirthday[family];
    }

    void addFamilyMemberBirthday(const pair<string, string> &family, const string &date) {
        if (!isContainFamilyMember(family)) {
            cout << family.first + family.second << "不存在，无法添加家庭成员生日信息.";
            return;
        }
        familyMemberBirthday[family] = date;
    }

    bool isContainFamilyMember(const string &family_name, const string &member_name) const {
        auto iter = familyCluster.find(family_name);
        auto cnt = familyCluster.count(family_name);
        for (; cnt > 0; --cnt) {
            if (iter++->second == member_name) {
                return true;
            }
        }
        return false;
    }

    bool isContainFamilyMember(const pair<string, string> &family) const {
        auto iter = familyCluster.find(family.first);
        auto cnt = familyCluster.count(family.first);
        for (; cnt > 0; --cnt) {
            if (iter++->second == family.second) {
                return true;
            }
        }
        return false;
    }

    vector<string> getFamilyMember(const string &family_name) const {
        vector<string> member;
        auto iter = familyCluster.find(family_name);
        auto cnt = familyCluster.count(family_name);
        if (cnt == 0) {
            cout << family_name << "姓没有家庭成员.";
        }
        for (; cnt > 0; --cnt) {
            member.emplace_back(iter++->second);
        }
        return member;
    }

    string getFamilyMemberBirthday(const pair<string, string> &family) const {
        if (!isContainFamilyMember(family)) {
            cout << family.first + family.second << "不存在,无法查询对应生日信息.";
            return null_str;
        }
        return familyMemberBirthday.at(family);
    }

private:
    string null_str = string("");
    // 允许使用多个重复的关键字，因此没必要使用vector去保存对应家庭成员的名了
    multimap<string, string> familyCluster;
    map<pair<string, string>, string> familyMemberBirthday;
};

int main(int argc, char **argv) {


    FamilyCluster familyCluster{"赵", "四"};

    string family_wang("王"), family_zhao("赵");

    familyCluster.addFamilyMember(family_wang, "五");
    familyCluster.addFamilyMember(family_wang, "二麻子");


    familyCluster.addFamilyMember(family_zhao, "四");
    familyCluster.addFamilyMember(family_zhao, "3");


    familyCluster.addFamilyMemberBirthday({family_wang, "4"}, "2019-10-05");
    familyCluster.addFamilyMemberBirthday({family_wang, "五"}, "2019-10-05");

    cout << endl;
    for (const auto &fw: familyCluster.getFamilyMember(family_wang))
        cout << family_wang + fw << " ";

    cout << endl << familyCluster.getFamilyMemberBirthday({family_wang, "2"}) << endl;
    cout << familyCluster.getFamilyMemberBirthday({family_wang, "五"}) << endl;

    for (const auto &fw: familyCluster.getFamilyMember(family_zhao))
        cout << family_zhao + fw << " ";
    return 0;
}


