#include "Chapter1/count_reverse_pairs.hpp"

TEST(ReversePairsTest, EmptyTest) {
    vector<int> empty_array;
    ASSERT_EQ(CountReversePairs(empty_array.begin(), empty_array.end()),
              0);
}

TEST(ReversePairsTest, CorrectnessTest) {
    {
        vector<int> array{2, 3, 8, 6, 1};
        ASSERT_EQ(CountReversePairs(array.begin(), array.end()),
                  5);
    }

    {
        vector<int> array{3, 5, 4, 2, 5, 1};
        ASSERT_EQ(CountReversePairs(array.begin(), array.end()),
                  9);
    }
}
