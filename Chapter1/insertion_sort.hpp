#ifndef INSERTIONT_SORT_HPP
#define INSERTIONT_SORT_HPP

#include "common/common.h"

template<typename Iterator>
void InsertionSort(Iterator begin, Iterator end) {
    for (auto current_key = begin + 1; current_key < end; ++current_key) {
        typename Iterator::reference key = *current_key;
        Iterator correct_position = current_key - 1;
        while (correct_position >= begin && *correct_position >= key) {
            *(correct_position + 1) = *correct_position;
            --correct_position;
        }
        *(correct_position + 1) = key;
    }
}

#endif
