/*
 * Exercise 12.22 为了能让StrBlobPtr使用const StrBlob,修改并定义一个ConstStrBlobPtr的类，使其能够指向const StrBlob
 * */

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <initializer_list>
#include <fstream>


using namespace std;

class ConstStrBlobPtr;

class StrBlob {
    // 声明友元类，使StrBlobPtr可以访问StrBlob的成员
    friend class ConstStrBlobPtr;

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

    ConstStrBlobPtr begin() const;

    ConstStrBlobPtr end() const;

private:
    shared_ptr<vector<string>> data;
};

// StrBlobPtr可以保证使用下标索引的时候范围的合法性
class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : pos(0) {}

    explicit ConstStrBlobPtr(const StrBlob &obj, size_t sz = 0) : pData(obj.data), pos(sz) {}

    ConstStrBlobPtr &operator++() {
        check(pos);
        ++pos;
        return *this;
    }

    ConstStrBlobPtr &operator--() {
        --pos;
        check(pos);
        return *this;
    }

    string &operator*() {
        return (*check(pos))[pos];
    }

    bool operator==(const ConstStrBlobPtr &right) const {
        auto pDataLeft = this->pData.lock();
        auto pDataRight = right.pData.lock();
        // 两个shared_ptr指向同一区域，且保证shared_ptr对象存在的情况下才比较位置是否相等
        if (pDataLeft == pDataRight && pDataLeft) {
            return pos == right.pos;
        }
        return false;
    }

    bool operator!=(const ConstStrBlobPtr &right) const {
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

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }

ConstStrBlobPtr StrBlob::end() const { return ConstStrBlobPtr(*this, this->size()); }


int main(int argc, char **argv) {
    const StrBlob b1 = {"a", "cc", "dd", "?"};
    for (auto begin = b1.begin(), end = b1.end(); begin != end; ++begin) {
        cout << *begin << " ";
    }
    return 0;
}


