#ifndef CHARPTER1_MERGE_SORT_HPP_H
#define CHARPTER1_MERGE_SORT_HPP_H

#include "common/common.h"
#include "Chapter1/insertion_sort.hpp"

template<typename Iterator>
void Merge(Iterator begin, Iterator mid, Iterator end) {
    vector<typename Iterator::value_type> l;
    vector<typename Iterator::value_type> r;
    for (auto it = begin; it != mid; ++it) {
        l.push_back(*it);
    }
    for (auto it = mid; it != end; ++it) {
        r.push_back(*it);
    }
    auto less_than = [&l, &r](Iterator l_iter, Iterator r_iter) {
        if (l_iter == l.end()) {
            return false;
        }
        if (r_iter == r.end()) {
            return true;
        }
        return *l_iter < *r_iter;
    };

    int length = end - begin;
    auto l_iter = l.begin();
    auto r_iter = r.begin();
    while (length-- > 0) {
        if (less_than(l_iter, r_iter)) {
            *begin++ = *l_iter++;
        } else {
            *begin++ = *r_iter++;
        }
    }
}

template<int InsertionSortThreshold, typename Iterator>
void MergeSortImp(Iterator begin, Iterator end) {
    if (end - begin <= InsertionSortThreshold) {
        InsertionSort(begin, end);
        return;
    }
    Iterator mid = begin + (end - begin) / 2;
    MergeSortImp<InsertionSortThreshold, Iterator>(begin, mid);
    MergeSortImp<InsertionSortThreshold, Iterator>(mid, end);
    Merge(begin, mid, end);
}

template<typename Iterator>
void MergeSort(Iterator begin, Iterator end) {
    MergeSortImp<1, Iterator>(begin, end);
}

#endif
