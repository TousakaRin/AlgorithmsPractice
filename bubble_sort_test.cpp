#include "common.h"
#include "bubble_sort.hpp"

TEST(TestBubbleSort, EmptyTest) {
   vector<int> array;
   BubbleSort(array.begin(), array.end());
}

TEST(TestInsertionSort, CorrectTest) {
   vector<int> array{3, 5, 6, 2, 3, 1, 5};
   BubbleSort(array.begin(), array.end());
   for (auto it = array.begin(); it < array.end() - 1; ++it) {
       ASSERT_LE(*it, *(it + 1));
   }
}