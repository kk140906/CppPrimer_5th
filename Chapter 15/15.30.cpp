/**
 * Exercise 15.30 编写自己的basket类，用它计算上一个练习中的交易记录的总价
 */


#include <iostream>
#include "../common/header/Quote.h"
#include <vector>
#include <memory>
#include <set>

using namespace std;

class Basket {
    using sp_Quote = shared_ptr<Quote>;
    using csp_Quote = const shared_ptr<Quote>;
public:
    void add_item(sp_Quote &&q) { items.insert(std::move(q)); }

    void add_item(const Quote &q) {
        items.insert(make_shared<Quote>(q));
    }

    void add_item(Quote &&q) { items.insert(make_shared<Quote>(std::move(q))); }

    void total_receipt(ostream &os) {
        double total_price = 0;
        for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
            total_price += print_totals(os, **iter, items.count(*iter));
            cout << endl;
        }
        cout << "Total Price: " << total_price << endl;
    }

private:
    static bool compareISBN(csp_Quote &lhs, csp_Quote &rhs) {
        return lhs->isbn() < rhs->isbn();
    }

    // items的初始值是类内初始值
    multiset<sp_Quote, decltype(compareISBN) *> items{compareISBN};
};


int main() {


    Basket vq_sp;
    // push_back时shared_ptr<Bulk_quote>被转换成了shared_ptr<Quote>
    auto bq = Bulk_quote("1", 10, 5, 0.8);
    vq_sp.add_item(bq);
    vq_sp.add_item(std::make_shared<Bulk_quote>("1", 20, 20, 0.65));
    vq_sp.add_item(Bulk_quote("1", 30, 50, 0.7));
    vq_sp.add_item(std::make_shared<Bulk_quote>("1", 40, 10, 0.85));

    vq_sp.total_receipt(cout);


    return 0;
}

