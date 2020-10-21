//
// Created by KK on 2020/10/18.
//

#include "13.44.String.h"

std::allocator<Exercise1344::Strings::values_t> Exercise1344::Strings::alloc;

namespace Exercise1344 {
    Strings::iter_pair Strings::alloc_n_copy(iter_ct b, iter_ct e) {
        auto new_p_start = alloc.allocate(e - b);
        auto new_p_end = std::uninitialized_copy(b, e, new_p_start);
        return {new_p_start, new_p_end};
    }

    Strings::iter_pair Strings::alloc_n_move(Strings::iter_ct b, Strings::iter_ct e) {
        auto new_p_start = alloc.allocate(e - b);
        auto new_p_end = std::uninitialized_copy(b, e, new_p_start);
        return {new_p_start, new_p_end};

    }

    Strings::size_t Strings::size() const { return p_end - p_start; }

    void Strings::free() {
        if (!p_start) {
            std::for_each(p_start, p_end, [](const auto &cc) { alloc.destroy(&cc); });
            alloc.deallocate(p_start, size());
        }
    }

    void Strings::copy_iter(iter_ct b, iter_ct e) {
        auto new_iter_pair = alloc_n_copy(b, e);
        p_start = new_iter_pair.first;
        p_end = new_iter_pair.second;
    }

    void Strings::move_iter(Strings::iter_t &b, Strings::iter_t &e) {
        p_start = b;
        p_end = e;
        b = e = nullptr;
    }

    Strings &Strings::operator=(const Strings &rs) {
        std::cout << "调用拷贝赋值运算符" << std::endl;
        auto new_iter_pair = alloc_n_copy(rs.cbegin(), rs.cend());
        free();
        p_start = new_iter_pair.first;
        p_end = new_iter_pair.second;
        return *this;
    }

    Strings &Strings::operator=(Strings &&rs) noexcept {
        std::cout << "调用移动赋值运算符" << std::endl;
        // 判断是否是自赋值
        if (this != &rs) {
            free();
            move_iter(rs.p_start, rs.p_end);
        }
        return *this;
    }


}
