//
// Created by KK on 2020/11/8.
//

#ifndef C___PRIMER_EXERCISE_HASH_SALES_DATA_H
#define C___PRIMER_EXERCISE_HASH_SALES_DATA_H

#include "Sales_data.h"

namespace std {
    template<>
    struct hash<Sales_data> {
        using result_type = size_t;
        using argument_type = Sales_data;

        result_type operator()(const Sales_data &sales_data) const {
            return hash<string>()(sales_data.book_isbn) ^
                   hash<double>()(sales_data.sold_price) ^
                   hash<size_t>()(sales_data.sold_counts);
        }
    };
}
#endif //C___PRIMER_EXERCISE_HASH_SALES_DATA_H
