//
// Created by KK on 2020/10/18.
//

#include "../header/String.h"

std::allocator<Strings::values_t> Strings::alloc;

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


std::ostream &operator<<(std::ostream &os, const Strings &s) {
    auto begin = s.p_start;
    while (begin != s.p_end) {
        os << *begin++;
    }
    return os;
}

bool operator==(const Strings &ls, const Strings &rs) {
    if (ls.size() != rs.size()) {
        return false;
    }
    // 长度相等利用strncmp比较，相等返回0
    return !strncmp(ls.p_start, rs.p_start, ls.size());
}

bool operator!=(const Strings &ls, const Strings &rs) { return !(ls == rs); }

bool operator<(const Strings &ls, const Strings &rs) {

    return std::lexicographical_compare(ls.p_start, ls.p_start, rs.p_start, rs.p_end);
}

char &Strings::operator[](size_t n) {
    if (n > size() || n < 0) {
        throw std::out_of_range("下标超出范围.");
    }
    return *(p_start + n);
}
