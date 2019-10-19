#include "common.h"

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

TEST(TestInsertionSort, EmptyTest) {
   vector<int> array;
   InsertionSort(array.begin(), array.end());
}

TEST(TestInsertionSort, CorrectTest) {
   vector<int> array{3, 5, 6, 2, 3, 1, 5};
   InsertionSort(array.begin(), array.end());
   for (auto it = array.begin(); it < array.end() - 1; ++it) {
       ASSERT_LE(*it, *(it + 1));
   }
}