//
// Created by KK on 2020/10/22.
//

#ifndef C___PRIMER_EXERCISE_SALES_DATA_H
#define C___PRIMER_EXERCISE_SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {

    friend std::ostream &operator<<(std::ostream &os, const Sales_data &sd);

    friend std::istream &operator>>(std::istream &is, Sales_data &sd);

    friend Sales_data operator+(const Sales_data &lsd, const Sales_data &rsd);

public:
    Sales_data() = default;

    Sales_data(std::string isbn, std::size_t sold_n, double price) :
            book_isbn(std::move(isbn)),
            sold_counts(sold_n),
            sold_price(price) {}

    std::string isbn() const { return book_isbn; }

    Sales_data &operator+=(const Sales_data &rsd) {
        if (this->book_isbn == rsd.book_isbn) {
            this->sold_counts += rsd.sold_counts;
        } else {
            throw std::invalid_argument("两本书籍的ISBN号不匹配.");
        }
        return *this;
    }

    Sales_data &operator=(std::string isbn) {
        book_isbn = std::move(isbn);
        return *this;
    }

private:
    std::string book_isbn;
    std::size_t sold_counts = 0;
    double sold_price = 0.0;
};

std::istream &operator>>(std::istream &is, Sales_data &sd) {
    std::string isbn;
    std::size_t counts;
    double price;
    std::cout << "请输入书籍的ISBN号:" << std::endl;
    is >> isbn;
    std::cout << "请输入书籍的销售数量:" << std::endl;
    is >> counts;
    std::cout << "请输入书籍的销售价格:" << std::endl;
    is >> price;
    if (is) {
        sd.book_isbn = isbn;
        sd.sold_counts = counts;
        sd.sold_price = price;
    } else {
        throw std::invalid_argument("输入参数无效.");
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &sd) {
    os << "ISBN: "
       << sd.book_isbn
       << " 销售数量: "
       << sd.sold_counts
       << " 销售价格: "
       << sd.sold_price;
    return os;
}

Sales_data operator+(const Sales_data &lsd, const Sales_data &rsd) {
    Sales_data sd = lsd;
    sd += rsd;
    return sd;
}

#endif //C___PRIMER_EXERCISE_SALES_DATA_H
