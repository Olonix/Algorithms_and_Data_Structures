#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& data, int target)
{
    std::unordered_map<int, int> hashData;
    int i;

    for (i = 0; i < std::size(data); i++)
    {
        if (hashData.count(target - data[i]) > 0)
        {
            return std::vector<int>{hashData[target - data[i]], i};
        }
        hashData[data[i]] = i;
    }

    return {};
}


TEST(TwoSumTest, BasicExample)
{
    std::vector<int> nums = {7, 15, 11, 2};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 3);
}

TEST(TwoSumTest, NotFound)
{
    std::vector<int> nums = {1, 2, 3};
    int target = 7;
    std::vector<int> result = twoSum(nums, target);
    EXPECT_TRUE(result.empty());
}

TEST(TwoSumTest, NegativeNumbers)
{
    std::vector<int> nums = {-3, -1, -5, -4, -2};
    int target = -8;
    std::vector<int> result = twoSum(nums, target);
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 2);
}

TEST(TwoSumTest, MultipleSolutions)
{
    std::vector<int> nums = {3, 5, 4, 3, 2};
    int target = 6;
    std::vector<int> result = twoSum(nums, target);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}