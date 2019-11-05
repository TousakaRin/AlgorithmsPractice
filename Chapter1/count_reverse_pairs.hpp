#ifndef CHAPTER1_COUNT_REVERSE_PAIRS_HPP
#define CHAPTER1_COUNT_REVERSE_PAIRS_HPP

#include "common/common.h"

template<typename Iterator>
int CountReversePairs(Iterator begin, Iterator end) {
    auto merge_and_count = [](Iterator begin, Iterator mid, Iterator end) -> int {
        vector<typename Iterator::value_type> l;
        vector<typename Iterator::value_type> r;
        for (auto it = begin; it != mid; ++it) {
            l.push_back(*it);
        }
        for (auto it = mid; it != end; ++it) {
            r.push_back(*it);
        }
        auto less_than = [&l, &r] (Iterator l_iter, Iterator r_iter) {
            if (l_iter == l.end()) {
                return false;
            }
            if (r_iter == r.end()) {
                return true;
            }
            return *l_iter <= *r_iter;
        };
        int length = end - begin;
        int reverse_pair_count = 0;
        auto l_iter = l.begin();
        auto r_iter = r.begin();
        while (length-- > 0) {
            if (less_than(l_iter, r_iter)) {
                *begin++ = *l_iter++;
            } else {
                reverse_pair_count += l.end() - l_iter;
                *begin++ = *r_iter++;
            }
        }
        return reverse_pair_count;
    };
    if (end - begin < 2) {
        return 0;
    }
    Iterator mid = begin + (end - begin) / 2;
    return CountReversePairs(begin, mid) +
           CountReversePairs(mid, end) +
           merge_and_count(begin, mid, end);
}

#endif
