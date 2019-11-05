#include "Chapter1/find_max_subarray.cpp"

bool CheckCorrectness(const vector<int>& array, Tuple result) {
    bool position_correct = false;
    for (size_t begin = 0; begin < array.size(); ++begin) {
        for (size_t end = begin + 1; end <= array.size(); ++end) {
            int sum = 0;
            for (size_t i = begin; i < end; ++i) {
                sum += array[i];
            }
            if (sum > get<2>(result)) {
                return false;
            }
            if (sum == get<2>(result) &&
                static_cast<int>(begin) == get<0>(result) - array.begin() &&
                static_cast<int>(end) == get<1>(result) - array.begin()) {
                position_correct = true;
            }
        }
    }
    return position_correct;
}

TEST(TestFindMaxSubarray, CorrectnessTest) {
    vector<int> array{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    auto result = FindMaxSubarray(array.begin(), array.end());
    ASSERT_TRUE(CheckCorrectness(array, result));
}

TEST(TestFindMaxSubarray, NegativeArraryTest) {
    vector<int> array{-3, -4, -1, -9, -10, -12, -11, -8, -7};
    auto result = FindMaxSubarray(array.begin(), array.end());
    ASSERT_TRUE(CheckCorrectness(array, result));
    ASSERT_EQ(get<2>(result), -1);
}
