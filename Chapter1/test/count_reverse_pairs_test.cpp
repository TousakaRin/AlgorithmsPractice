#include "Chapter1/count_reverse_pairs.hpp"

TEST(ReversePairsTest, UT) {
    vector<int> empty_array;
    ASSERT_EQ(CountReversePairs(empty_array.begin(), empty_array.end()), 
              0);

    vector<int> array{2, 3, 8, 6, 1};
    ASSERT_EQ(CountReversePairs(array.begin(), array.end()),
              5);
}
