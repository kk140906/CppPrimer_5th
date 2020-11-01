//
// Created by KK on 2020/10/31.
//

#include "../header/StrBlob.h"

bool StrBlob::empty() const { return sp_container->empty(); }

std::size_t StrBlob::size() const { return sp_container->size(); }

void StrBlob::push_back(const values &val) { sp_container->push_back(val); }

StrBlob::values StrBlob::pop_back() {
    if (!empty()) {
        values str = sp_container->back();
        sp_container->pop_back();
        return str;
    } else {
        return values();
    }
}

bool operator==(const StrBlob &lsb, const StrBlob &rsb) {
    // shared_ptr类定义了==，可以直接使用
    return lsb.sp_container == rsb.sp_container;
}

bool operator!=(const StrBlob &lsb, const StrBlob &rsb) {
    return !(lsb == rsb);
}

bool operator<(const StrBlob &lsb, const StrBlob &rsb) {
    return std::lexicographical_compare(lsb.sp_container->cbegin(), lsb.sp_container->cend(),
                                        rsb.sp_container->cbegin(), rsb.sp_container->cend());
}
