#include "Chapter1/merge_sort.hpp"

constexpr int kIsertionSortThreshold = 3;

TEST(TestMergeSort, EmptyTest) {
   vector<int> array;
   MergeSort(array.begin(), array.end());
   MergeSortImp<kIsertionSortThreshold>(array.begin(), array.end());
}

TEST(TestMergeSort, CorrectnessTest) {
   vector<int> array{3, 5, 6, 2, 3, 1, 5};
   MergeSort(array.begin(), array.end());
   for (auto it = array.begin(); it < array.end() - 1; ++it) {
       ASSERT_LE(*it, *(it + 1));
   }
}

TEST(TestMergeSortImp, CorrectnessTest) {
   vector<int> array{3, 5, 6, 2, 3, 1, 5};
   MergeSortImp<kIsertionSortThreshold>(array.begin(), array.end());
   for (auto it = array.begin(); it < array.end() - 1; ++it) {
       ASSERT_LE(*it, *(it + 1));
   }
}
