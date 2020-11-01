/*
 * Exercise 15.28 定义一个存放Quote对象的vector，将Bulk_quote的对象传入其中，计算vector中所有元素的net_price的总和
 * Exercise 15.29 重新定义新的vector保存Quote的智能指针，将Bulk_quote的对象传入其中，计算vector中所有元素的net_price的总和
 */


#include <iostream>
#include "../common/header/Quote.h"
#include <vector>
#include <memory>

using namespace std;

int main() {
#ifdef Exercise1528
    vector<Quote> vq;
    vq.push_back(Bulk_quote("1", 10, 5, 0.8));
    vq.push_back(Bulk_quote("2", 20, 20, 0.65));
    vq.push_back(Bulk_quote("3", 30, 50, 0.7));
    vq.push_back(Bulk_quote("4", 40, 10, 0.85));
    double total_price = 0;
    for (const auto &cv : vq) {
        total_price += cv.net_price(30);
    }
    cout << "总消费: " << total_price << endl;
#else
    vector<shared_ptr<Quote>> vq_sp;
    // push_back时shared_ptr<Bulk_quote>被转换成了shared_ptr<Quote>
    vq_sp.push_back(std::make_shared<Bulk_quote>("1", 10, 5, 0.8));
    vq_sp.push_back(std::make_shared<Bulk_quote>("2", 20, 20, 0.65));
    vq_sp.push_back(std::make_shared<Bulk_quote>("3", 30, 50, 0.7));
    vq_sp.push_back(std::make_shared<Bulk_quote>("4", 40, 10, 0.85));
    double total_price = 0;
    for (const auto &cv : vq_sp) {
        // 指向派生类对象的基类指针在调用虚函数时会发生动态绑定，实际运行的是派生类的虚函数
        total_price += cv->net_price(30);
    }
    cout << "总消费: " << total_price << endl;
#endif

    return 0;
}

