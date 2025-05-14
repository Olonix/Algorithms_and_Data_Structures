#include <vector>

int pivotIndex(std::vector<int>& nums) {
    int totalSum = 0;
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];
    }
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}


#include <gtest/gtest.h>

TEST(PivotIndexTest, BasicCase) {
    std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    EXPECT_EQ(pivotIndex(nums), 3);
}

TEST(PivotIndexTest, NoPivot) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(pivotIndex(nums), -1);
}

TEST(PivotIndexTest, PivotAtZero) {
    std::vector<int> nums = {2, 1, -1};
    EXPECT_EQ(pivotIndex(nums), 0);
}

TEST(PivotIndexTest, AllZeros) {
    std::vector<int> nums = {0, 0, 0, 0};
    EXPECT_EQ(pivotIndex(nums), 0);
}

TEST(PivotIndexTest, SingleElement) {
    std::vector<int> nums = {10};
    EXPECT_EQ(pivotIndex(nums), 0);
}

TEST(PivotIndexTest, EmptyArray) {
    std::vector<int> nums = {};
    EXPECT_EQ(pivotIndex(nums), -1);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}