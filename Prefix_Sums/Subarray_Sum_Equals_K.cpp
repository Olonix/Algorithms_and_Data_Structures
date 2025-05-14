#include <vector>
#include <unordered_map>

int subarraySum(const std::vector<int>& nums, int k) {
    int prefixSum = 0;
    std::unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            count += prefixCount[prefixSum - k];
        }
        prefixCount[prefixSum]++;
    }
    return count;
}


#include <gtest/gtest.h>

TEST(SubarraySumTest, BasicCase) {
    std::vector<int> nums = {1, 1, 1};
    EXPECT_EQ(subarraySum(nums, 2), 2);
}

TEST(SubarraySumTest, ZeroSum) {
    std::vector<int> nums = {1, -1, 1, -1, 1};
    EXPECT_EQ(subarraySum(nums, 0), 6);
}

TEST(SubarraySumTest, NegativeK) {
    std::vector<int> nums = {-1, -1, 1};
    EXPECT_EQ(subarraySum(nums, -1), 3);
}

TEST(SubarraySumTest, NoSubarray) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(subarraySum(nums, 7), 0);
}

TEST(SubarraySumTest, AllZeros) {
    std::vector<int> nums = {0, 0, 0, 0};
    EXPECT_EQ(subarraySum(nums, 0), 10);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}