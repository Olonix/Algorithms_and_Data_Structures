#include <vector>
#include <algorithm>  

int coinChange(const std::vector<int>& coins, int amount) {
    if (amount == 0) {
        return 0;
    }

    int infinity_val = amount + 1;
    std::vector<int> dp(amount + 1, infinity_val);
    dp[0] = 0; 

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin > 0 && coin <= i) { 
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == infinity_val) {
        return -1; 
    }
    return dp[amount];
}

#include "gtest/gtest.h"

TEST(CoinChangeTest, Example1) {
    EXPECT_EQ(coinChange({1, 2, 5}, 11), 3);
}

TEST(CoinChangeTest, AmountZero) {
    EXPECT_EQ(coinChange({1, 2, 3}, 0), 0);
}

TEST(CoinChangeTest, EmptyCoinsAmountPositive) {
    EXPECT_EQ(coinChange({}, 5), -1);
}

TEST(CoinChangeTest, EmptyCoinsAmountZero) {
    EXPECT_EQ(coinChange({}, 0), 0); 
}

TEST(CoinChangeTest, SingleCoinTypeExactMatch) {
    EXPECT_EQ(coinChange({5}, 10), 2);
}

TEST(CoinChangeTest, SingleCoinTypeNoMatch) {
    EXPECT_EQ(coinChange({2}, 3), -1);
}

TEST(CoinChangeTest, AllCoinsLargerThanAmount) {
    EXPECT_EQ(coinChange({5, 10, 15}, 3), -1);
}

TEST(CoinChangeTest, OptimalChoiceNotGreedy) {
    EXPECT_EQ(coinChange({1, 3, 4}, 6), 2);
}

TEST(CoinChangeTest, LargeAmountSmallCoins) {
    EXPECT_EQ(coinChange({1}, 100), 100);
}

TEST(CoinChangeTest, ComplexCase) {
    EXPECT_EQ(coinChange({186, 419, 83, 408}, 6249), 20);
}

TEST(CoinChangeTest, NoSolutionPossible) {
    EXPECT_EQ(coinChange({2, 4, 6}, 7), -1); 
}

TEST(CoinChangeTest, CoinValueEqualToAmount) {
    EXPECT_EQ(coinChange({5, 2, 10}, 10), 1); 
    EXPECT_EQ(coinChange({1, 2, 7}, 7), 1); 
}

TEST(CoinChangeTest, CoinsWithZeroValue) {
    EXPECT_EQ(coinChange({1, 0, 2}, 5), 3); 
}

TEST(CoinChangeTest, UnsortedCoins) {
    EXPECT_EQ(coinChange({5, 1, 2}, 11), 3);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}