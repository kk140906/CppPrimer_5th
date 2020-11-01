//
// Created by KK on 2020/10/26.
//

#ifndef C___PRIMER_EXERCISE_QUOTE_H
#define C___PRIMER_EXERCISE_QUOTE_H

#include <iostream>
#include <string>

class Quote {
public:
    Quote() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Quote(const std::string &bookSn, const double &price) : bookNo(bookSn), sold_price(price) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Quote(const Quote &q) : bookNo(q.bookNo), sold_price(q.sold_price) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Quote(Quote &&q) : bookNo(std::move(q.bookNo)), sold_price(std::move(q.sold_price)) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Quote &operator=(const Quote &rhs) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        bookNo = rhs.bookNo;
        sold_price = rhs.sold_price;
        return *this;
    }

    Quote &operator=(Quote &&rhs) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        bookNo = std::move(rhs.bookNo);
        sold_price = std::move(rhs.sold_price);
        return *this;
    }

    // 模拟虚拷贝
    virtual Quote *clone() const &{ return new Quote(*this); }

    virtual Quote *clone() const &&{ return new Quote(std::move(*this)); }

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const { return sold_price * n; }

    virtual void debug() const { std::cout << "ISBN: " << bookNo << " price:" << sold_price; }

    virtual ~Quote() { std::cout << __PRETTY_FUNCTION__ << std::endl; };


private:
    std::string bookNo;
protected:
    double sold_price;
};

class Discount_quote : public Quote {
public:
    Discount_quote() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Discount_quote(const std::string &bookSn,
                   const double &price,
                   const std::size_t &counts,
                   const double &dis) : Quote(bookSn, price),
                                        sold_counts(counts),
                                        discount(dis) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Discount_quote(const Discount_quote &rhs) : Quote(rhs),
                                                sold_counts(rhs.sold_counts),
                                                discount(rhs.discount) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Discount_quote(Discount_quote &&rhs) : Quote(std::move(rhs)),
                                           sold_counts(std::move(rhs.sold_counts)),
                                           discount(std::move(rhs.discount)) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Discount_quote &operator=(const Discount_quote &rhs) {

        std::cout << __PRETTY_FUNCTION__ << std::endl;
        // 显式的调用基类的拷贝赋值运算符为派生类中的基类部分赋值
        Quote::operator=(rhs);
        sold_counts = rhs.sold_counts;
        discount = rhs.discount;
        return *this;
    }

    Discount_quote &operator=(Discount_quote &&rhs) {

        std::cout << __PRETTY_FUNCTION__ << std::endl;
        // 显式的调用基类的移动赋值运算符为派生类中的基类部分赋值
        Quote::operator=(std::move(rhs));
        sold_counts = std::move(rhs.sold_counts);
        discount = std::move(rhs.discount);
        return *this;
    }

    virtual double net_price(std::size_t n) const = 0;

protected:
    std::size_t sold_counts;
    double discount;
};

class Bulk_quote : public Discount_quote {
public:
    Bulk_quote() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Bulk_quote(const std::string &bookSn,
               const double &price,
               const std::size_t &counts,
               const double &dis) : Discount_quote(bookSn, price, counts, dis) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

#ifdef Exercise1527
    using Discount_quote::Discount_quote;
#else

    Bulk_quote(const Bulk_quote &rhs) : Discount_quote(rhs) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Bulk_quote(Bulk_quote &&rhs) : Discount_quote(std::move(rhs)) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Bulk_quote &operator=(const Bulk_quote &rhs) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Discount_quote::operator=(rhs);
        return *this;
    }

    Bulk_quote &operator=(Bulk_quote &&rhs) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Discount_quote::operator=(std::move(rhs));
        return *this;
    }

#endif

    Bulk_quote *clone() const &{ return new Bulk_quote(*this); }

    Bulk_quote *clone() const &&{ return new Bulk_quote(std::move(*this)); }

    // 重写基类的虚函数，购买数量超过一定数量时打折
    double net_price(std::size_t n) const override {
        return (n > sold_counts ? discount : 1) * n * sold_price;
    }

    virtual void debug() const {
        Quote::debug();
        std::cout << std::endl;
        std::cout << "sold_minCounts: " << sold_counts
                  << " discount:" << discount;
    }
};

class Limit_quote : public Discount_quote {
public:
    Limit_quote() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Limit_quote(const std::string &bookSn,
                const double &price,
                const std::size_t &counts,
                const double &dis) : Discount_quote(bookSn, price, counts, dis) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Limit_quote(const Limit_quote &rhs) : Discount_quote(rhs) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Limit_quote(Limit_quote &&rhs) : Discount_quote(std::move(rhs)) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Limit_quote &operator=(const Limit_quote &rhs) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Discount_quote::operator=(rhs);
        return *this;
    }

    Limit_quote &operator=(Limit_quote &&rhs) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Discount_quote::operator=(std::move(rhs));
        return *this;
    }

    Limit_quote *clone() const &{ return new Limit_quote(*this); }

    Limit_quote *clone() const &&{ return new Limit_quote(std::move(*this)); }

    // 重写基类的虚函数，购买数量低于一定数量时打折，超过时按原价销售
    double net_price(std::size_t n) const override {
        return (n <= sold_counts ?
                discount * n :
                ((discount - 1) * sold_counts + n)) * sold_price;
    }

    virtual void debug() const {
        Quote::debug();
        std::cout << std::endl;
        std::cout << "sold_minCounts: " << sold_counts
                  << " discount:" << discount;
    }

};

double print_totals(std::ostream &os, const Quote &q, const std::size_t &counts) {

    os << "ISBN:" << q.isbn() << " sold: " << counts << " total price:" << q.net_price(counts);
    return q.net_price(counts);
}

#endif //C___PRIMER_EXERCISE_QUOTE_H
