#include <vector>
#include <algorithm>

int maxSubarraySum(const std::vector<int>& arr, int k) {
    if (arr.size() < k) {
        return -1;
    }
    int currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }
    int maxSum = currentSum;
    for (int i = k; i < arr.size(); i++) {
        currentSum = currentSum - arr[i - k] + arr[i];
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
}


#include <gtest/gtest.h>

TEST(MaxSubarraySumTest, NormalCase) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxSubarraySum(arr, 3), 12);
}

TEST(MaxSubarraySumTest, WholeArray) {
    std::vector<int> arr = {4, -1, 2, 1};
    EXPECT_EQ(maxSubarraySum(arr, 4), 6);
}

TEST(MaxSubarraySumTest, NegativeNumbers) {
    std::vector<int> arr = {-2, -3, -1, -4};
    EXPECT_EQ(maxSubarraySum(arr, 2), -4);
}

TEST(MaxSubarraySumTest, KEqualsOne) {
    std::vector<int> arr = {5, 1, 3, 2};
    EXPECT_EQ(maxSubarraySum(arr, 1), 5);
}

TEST(MaxSubarraySumTest, KTooLarge) {
    std::vector<int> arr = {1, 2};
    EXPECT_EQ(maxSubarraySum(arr, 3), -1);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
