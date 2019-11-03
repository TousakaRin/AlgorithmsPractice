#ifndef ALGORITHMS_PRACTICE_COMMON_H_
#define ALGORITHMS_PRACTICE_COMMON_H_

#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <memory>

#include <gtest/gtest.h>

using namespace std;

template<typename Iterator>
string DebugString(Iterator begin, Iterator end) {
    string result = "[";
    for (auto it = begin; it != end; ++it) {
        result += to_string(*it) + " ";
    }
    if (result.size() != 1) {
        result.pop_back();
    }
    result += "]";
    return result;
}

template<typename Container>
string DebugString(const Container& container) {
    return DebugString(container.begin(), container.end());
}

#endif
