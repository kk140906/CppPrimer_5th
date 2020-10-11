/*
 * Exercise 12.19 定义自己的StrBlobPtr类，包含一个weak_ptr指向StrBlob的data成员
 * Exercise 12.20 逐行读取一个输入文件，将内容存入一个StrBlob中，用一个StrBlobPtr打印出StrBlob中所有元素
 * */

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <initializer_list>
#include <fstream>


using namespace std;

class StrBlobPtr;

class StrBlob {
    // 声明友元类，使StrBlobPtr可以访问StrBlob的成员
    friend class StrBlobPtr;

public:
    // 使用make_shared创建智能指针更为安全
    StrBlob() : data(make_shared<vector<string>>()) {}
    // 直接初始化会创建一个空的智能指针，一旦用户忘记了初始化，在这个指针上的所有操作都是非法的
    /*
     * auto p1 = shared_ptr<vector<string>>(); // p1返回值为nullptr,p1.use_count()为0
     * auto p2 = make_shared<vector<string>>(); // p2返回值为一个智能指针指向的地址,p2.use_count()为1
     *
     */
//    StrBlob() : data(shared_ptr<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    std::size_t size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    string front() const {
        if (!empty()) {
            return data->front();
        }
        return string();
    }

    string back() const {
        if (!empty()) {
            return data->back();
        }
        return string();
    }

    void useCount(const string &identify) {
        cout << identify << " - 引用计数: " << data.use_count() << endl;
    }

    void push_back(const string &s) { data->push_back(s); }

    void pop_back() { if (!empty()) data->pop_back(); }

    StrBlobPtr begin();

    StrBlobPtr end();

private:
    shared_ptr<vector<string>> data;
};

// StrBlobPtr可以保证使用下标索引的时候范围的合法性
class StrBlobPtr {
public:
    StrBlobPtr() : pos(0) {}

    explicit StrBlobPtr(StrBlob &obj, size_t sz = 0) : pData(obj.data), pos(sz) {}

    StrBlobPtr &operator++() {
        check(pos);
        ++pos;
        return *this;
    }

    StrBlobPtr &operator--() {
        --pos;
        check(pos);
        return *this;
    }

    string &operator*() {
        return (*check(pos))[pos];
    }

    bool operator==(const StrBlobPtr &right) const {
        auto pDataLeft = this->pData.lock();
        auto pDataRight = right.pData.lock();
        // 两个shared_ptr指向同一区域，且保证shared_ptr对象存在的情况下才比较位置是否相等
        if (pDataLeft == pDataRight && pDataLeft) {
            return pos == right.pos;
        }
        return false;
    }

    bool operator!=(const StrBlobPtr &right) const {
        return !(*this == right);
    }

private:
    size_t pos;
    weak_ptr<vector<string>> pData;

    shared_ptr<vector<string>> check(const size_t &position) {
        auto ret = pData.lock();
        if (!ret) {
            throw runtime_error("Bounded StrBlob Object is deleted");
        } else if (position >= ret->size()) {
            throw out_of_range("StrBlob Object index more than the last index");
        } else if (position < 0) {
            throw out_of_range("StrBlob Object index less than the first index");
        }
        return ret;
    }
};

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, this->size()); }


int main(int argc, char **argv) {
    // make_shared 测试
    auto p1 = shared_ptr<string>();
    cout << "shared_ptr : p1 = " << p1 << " ,引用计数 : p1.use_count() = " << p1.use_count() << endl;
    auto p2 = make_shared<string>();
    cout << "make_shared : p2 = " << p2 << " ,引用计数 : p2.use_count() = " << p2.use_count() << endl;
    cout << endl;


    StrBlob b1, b3;
    cout << "push_back : a" << endl;
    b1.push_back("a");
    b3.push_back("tt");


    cout << "front: " << b1.front() << endl;
    cout << "back: " << b1.back() << endl;
    cout << "push_back : cc";
    b1.push_back("cc");
    cout << "front: " << b1.front() << endl;
    cout << "back: " << b1.back() << endl;
    for (auto iter = b1.begin(), end = b1.end(); iter != end; ++iter) {
        cout << *iter << " ";
    }
    cout << endl;


    string fileName("12.20.testFile.txt");
    ifstream in_file(fileName);
    if (!in_file) {
        cout << fileName << " 打开失败" << endl;
        return 0;
    }
    string word;
    StrBlob b2;
    while (getline(in_file, word)) {
        b2.push_back(word);
    }

    cout << endl;
    for (auto iter = b2.begin(), end = b2.end(); iter != end; ++iter) {
        cout << *iter << endl;
    }

    return 0;
}


