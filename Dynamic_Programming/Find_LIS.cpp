#include <vector>
#include <algorithm>

int findLIS(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    
    std::vector<int> dp(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] < nums[i]) {
            dp[i] = dp[i - 1] + 1;
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

#include "gtest/gtest.h"

TEST(FindLISTest, EmptyArray) {
    EXPECT_EQ(findLIS({}), 0);
}

TEST(FindLISTest, SingleElement) {
    EXPECT_EQ(findLIS({5}), 1);
    EXPECT_EQ(findLIS({0}), 1);
    EXPECT_EQ(findLIS({-10}), 1);
}

TEST(FindLISTest, Example1) {
    EXPECT_EQ(findLIS({3, 2, 8, 9, 5, 10}), 3);
}

TEST(FindLISTest, Example2) {
    EXPECT_EQ(findLIS({1, 2, 7, 9, 0, 10}), 4);
}

TEST(FindLISTest, Example3) {
    EXPECT_EQ(findLIS({8, 8, 8, 8}), 1);
}

TEST(FindLISTest, AllIncreasing) {
    EXPECT_EQ(findLIS({1, 2, 3, 4, 5}), 5);
}

TEST(FindLISTest, AllDecreasing) {
    EXPECT_EQ(findLIS({5, 4, 3, 2, 1}), 1);
}

TEST(FindLISTest, MixedPositiveAndNegative) {
    EXPECT_EQ(findLIS({-1, 0, 1, -5, -4, -3, -2, -1, 0}), 6); 
}


TEST(FindLISTest, StartsWithDecreasingEndsWithIncreasing) {
    EXPECT_EQ(findLIS({5, 4, 3, 1, 2, 3, 4}), 4);
}

TEST(FindLISTest, OnlyTwoElements) {
    EXPECT_EQ(findLIS({1, 2}), 2);
    EXPECT_EQ(findLIS({2, 1}), 1);
    EXPECT_EQ(findLIS({1, 1}), 1);
}

TEST(FindLISTest, SequenceInTheMiddle) {
    EXPECT_EQ(findLIS({10, 20, 5, 6, 7, 8, 1, 2}), 4);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}