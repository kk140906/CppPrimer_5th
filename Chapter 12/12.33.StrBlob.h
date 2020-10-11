//
// Created by KK on 2020/10/11.
//

#ifndef C___PRIMER_EXERCISE_12_32_STRBLOB_H
#define C___PRIMER_EXERCISE_12_32_STRBLOB_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>


namespace Exercise1233 {

    class StrBlobPtr;

    class StrBlob {

        friend class StrBlobPtr;

        using container = std::vector<std::string>;
        using values = std::string;
    public:
        StrBlob() : sp_container(std::make_shared<container>()) {}

        explicit StrBlob(const values &str) : sp_container(std::make_shared<container>(container{str})) {}

        StrBlob(const std::initializer_list<values> &il) : sp_container(std::make_shared<container>(il)) {}

        bool empty() const;

        std::size_t size() const;

        void push_back(const values &val);

        values pop_back();

        StrBlobPtr begin();

        StrBlobPtr cbegin() const;

        StrBlobPtr end();

        StrBlobPtr cend() const;

        values operator[](int cur_pos);

    private:
        std::shared_ptr<container> sp_container;
    };

    inline bool StrBlob::empty() const { return sp_container->empty(); }

    inline std::size_t StrBlob::size() const { return sp_container->size(); }

    inline void StrBlob::push_back(const values &val) { sp_container->push_back(val); }

    inline StrBlob::values StrBlob::pop_back() {
        if (!empty()) {
            values str = sp_container->back();
            sp_container->pop_back();
            return str;
        } else {
            return values();
        }
    }


}
#endif //C___PRIMER_EXERCISE_12_32_STRBLOB_H
