//
// Created by KK on 2020/11/4.
//

#ifndef C___PRIMER_EXERCISE_DEBUG_DELETE_H
#define C___PRIMER_EXERCISE_DEBUG_DELETE_H

#include <iostream>

struct DebugDelete {
    template<typename Tp_>
    void operator()(const Tp_ &p) const {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        delete p;
    }
};

#endif //C___PRIMER_EXERCISE_DEBUG_DELETE_H
