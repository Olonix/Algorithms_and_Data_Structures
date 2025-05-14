#include <vector>
#include <unordered_map>
#include <algorithm>

int findMaxLength(const std::vector<int>& nums) {
    int prefixSum = 0;
    int maxLen = 0;
    std::unordered_map<int, int> indexMap;
    indexMap[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
         // Заменяем 0 на -1, 1 оставляем как 1
        prefixSum += (num == 0) ? -1 : 1;
        if (indexMap.find(prefixSum) != indexMap.end()) {
            maxLen = std::max(maxLen, i - indexMap[prefixSum]);
        } else {
            indexMap[prefixSum] = i;
        }
    }
    return maxLen;
}


#include <gtest/gtest.h>

TEST(FindMaxLengthTest, BasicCase) {
    std::vector<int> nums = {0, 1};
    EXPECT_EQ(findMaxLength(nums), 2);
}

TEST(FindMaxLengthTest, MultipleZerosAndOnes) {
    std::vector<int> nums = {0, 1, 0, 0, 1};
    EXPECT_EQ(findMaxLength(nums), 4);
}

TEST(FindMaxLengthTest, AllOnes) {
    std::vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(findMaxLength(nums), 0);
}

TEST(FindMaxLengthTest, AllZeros) {
    std::vector<int> nums = {0, 0, 0, 0};
    EXPECT_EQ(findMaxLength(nums), 0);
}

TEST(FindMaxLengthTest, LongAlternating) {
    std::vector<int> nums = {0, 1, 0, 1, 0, 1, 0, 1};
    EXPECT_EQ(findMaxLength(nums), 8);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}