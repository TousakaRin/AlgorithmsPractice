#include "common.h"

template<typename Iterator>
int CountReversePairs(Iterator begin, Iterator end) {
    auto merge_and_count = [](Iterator begin, Iterator mid, Iterator end) -> int {
        vector<Iterator::value_type> l;
        vector<Iterator::value_type> r;
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
            return *l_iter < *r_iter;
        }
        int length = end - mid;
        int reverse_pair_count = 0;
        auto l_iter = l.begin();
        auto r_iter = r.begin();
        while (length-- > 0) {
            if (less_than(l_iter, r_iter)) {
                *begin++ = *l_iter++;
            } else {
                ++reverse_pair_count;
                *begin++ = *r_iter++;
            }
        }
        return reverse_pair_count;
    };
    Iterator mid = begin + (end - begin) / 2;
    return sum<int>(CountReversePairs(begin, mid),
                    CountReversePairs(mid, end),
                    merge_and_count(begin, mid, end));
}

TEST(ReversePairsTest, UT) {
    vector<int> empty_array;
    ASSERT_EQ(CountReversePairs(empty_array.begin(), empty_array.end()),
              0);

    vector<int> array{2, 3, 8, 6, 1};
    ASSERT_EQ(CountReversePairs(array.begin(), array.end()),
              5);
}