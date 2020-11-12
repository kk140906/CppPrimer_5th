/**
 * @details: Exercise 17.4 编写测试自己版本的findBook函数
 * @details: Exercise 17.5 重写findBook，令其返回一个pair，一个索引和一个迭代器pair
 * @details: Exercise 17.6 重写findBook，不使用tuple和pair
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../common/header/Sales_data.h"

using namespace std;

// 每个书店自己的销售记录
using SalesDataLogType = vector<Sales_data>;
// 全部书店的销售记录
using AllSalesDataLogType = vector<SalesDataLogType>;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

// Tuple
using MatchBookTupleType = tuple<SalesDataLogType::size_type,
        SalesDataLogType::const_iterator,
        SalesDataLogType::const_iterator>;

vector<MatchBookTupleType> findBook(const string &isbn, const AllSalesDataLogType &allSalesDataLogType) {
    vector<MatchBookTupleType> result;
    for (auto begin = allSalesDataLogType.cbegin(), end = allSalesDataLogType.cend(); begin != end; ++begin) {
        // 注意equal_range第三个参数应该需要转换成Sales_data对象才能正确比较，书籍上应该有误,此外该算法的前提是已经排序完毕的对象
        auto found = equal_range(begin->cbegin(), begin->cend(), Sales_data(isbn), compareIsbn);
        if (found.first != found.second) {
            result.emplace_back(make_tuple(begin - allSalesDataLogType.cbegin(), found.first, found.second));
        }
    }
    return result;
}

// Pair
using MatchBookPairType = pair<SalesDataLogType::size_type,
        pair<SalesDataLogType::const_iterator, SalesDataLogType::const_iterator>>;

vector<MatchBookPairType> findBook_return_pair(const string &isbn, const AllSalesDataLogType &allSalesDataLogType) {
    vector<MatchBookPairType> result;
    for (auto begin = allSalesDataLogType.cbegin(), end = allSalesDataLogType.cend(); begin != end; ++begin) {
        auto found = equal_range(begin->cbegin(), begin->cend(), Sales_data(isbn), compareIsbn);
        if (found.first != found.second) {
            result.emplace_back(make_pair(begin - allSalesDataLogType.cbegin(), make_pair(found.first, found.second)));
        }
    }
    return result;
}

// struct
using MatchBookStructType = struct {
    SalesDataLogType::size_type index;
    SalesDataLogType::const_iterator cbegin, cend;
};

vector<MatchBookStructType> findBook_return_struct(const string &isbn, const AllSalesDataLogType &allSalesDataLogType) {
    vector<MatchBookStructType> result;
    for (auto begin = allSalesDataLogType.cbegin(), end = allSalesDataLogType.cend(); begin != end; ++begin) {
        auto found = equal_range(begin->cbegin(), begin->cend(), Sales_data(isbn), compareIsbn);
        if (found.first != found.second) {
            result.emplace_back(
                    MatchBookStructType{static_cast<SalesDataLogType::size_type>(begin - allSalesDataLogType.cbegin()),
                                        found.first, found.second});
        }
    }
    return result;
}

int main() {
    SalesDataLogType store1, store2, store3;
    store1.push_back(Sales_data("123", 10, 56.9));
    store2.push_back(Sales_data("123", 50, 40));
    store3.push_back(Sales_data("123", 13, 56.9));
    store1.push_back(Sales_data("abc", 10, 52.3));
    store2.push_back(Sales_data("123", 60, 38.5));
    store3.push_back(Sales_data("123", 20, 49.9));

    AllSalesDataLogType file{store1, store2, store3};

    string isbn("123");
    auto result = findBook(isbn, file);
    for (const auto &cr : result) {
        cout << "store "
             << get<0>(cr)
             << ": "
             << accumulate(get<1>(cr), get<2>(cr), Sales_data(isbn))
             << endl;
    }
    cout << endl;
    auto result_pair = findBook_return_pair(isbn, file);
    for (const auto &cr : result_pair) {
        cout << "store "
             << cr.first
             << ": "
             << accumulate(cr.second.first, cr.second.second, Sales_data(isbn))
             << endl;
    }
    cout << endl;
    auto result_struct = findBook_return_struct(isbn, file);
    for (const auto &cr : result_struct) {
        cout << "store "
             << cr.index
             << ": "
             << accumulate(cr.cbegin, cr.cend, Sales_data(isbn))
             << endl;
    }
    return 0;
}

