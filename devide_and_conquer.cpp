#include "common.h"

using Iterator = typename vector<int>::iterator;

tuple<Iterator, Iterator, int> FindMaxCrossingSubarray(Iterator begin, Iterator mid, Iterator end) {
    tuple<Iterator, Iterator, int> result;
    int left_max_sum = numeric_limits<int>::min();
    int left_sum = 0;
    for (auto it = mid - 1; mid >= begin; --mid) {
        left_sum += *it;
        if (left_sum > left_max_sum) {
            left_max_sum = left_sum;
            get<0>(result) = it;
        }
    }

    int right_max_sum = numeric_limits<int>::min();
    int right_sum = 0;
    for (auto it = mid; it != end; ++it) {
        right_sum += *it;
        if (right_sum > right_max_sum) {
            right_max_sum = right_sum;
            get<1>(result) = it;
        }
    }
    get<2>(result) = left_max_sum + right_max_sum;
    return result;
}

tuple<Iterator, Iterator, int> FindMaxSubarray(Iterator begin, Iterator end) {
    using Tuple = tuple<Iterator, Iterator, int>;
    assert(begin == end);
    if (end - begin == 1) {
        return Tuple(begin, end, 1);
    }
    auto less_than = [](const Tuple& lhs, const Tuple& rhs) {
        return get<2>(lhs) < get<2>(rhs);
    };
    auto mid = begin + (end - begin) / 2;
    return max(max(FindMaxSubarray(begin, mid), FindMaxSubarray(mid, end), less_than),
               FindMaxCrossingSubarray(begin, mid, end), less_than);

}
