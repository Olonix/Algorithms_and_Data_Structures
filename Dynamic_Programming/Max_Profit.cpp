#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty() || prices.size() < 2) {
        return 0;
    }

    int profit = 0;
    int min_price = prices[0];

    for (int i = 1; i < prices.size(); i++) {
        profit = std::max(profit, prices[i] - min_price);
        min_price = std::min(min_price, prices[i]);
    }

    return profit;
}

#include "gtest/gtest.h"

TEST(MaxProfitTest, EmptyArray) {
    EXPECT_EQ(maxProfit({}), 0);
}

TEST(MaxProfitTest, SingleElement) {
    EXPECT_EQ(maxProfit({10}), 0);
}

TEST(MaxProfitTest, TwoElementsIncreasing) {
    EXPECT_EQ(maxProfit({2, 5}), 3);
}

TEST(MaxProfitTest, TwoElementsDecreasing) {
    EXPECT_EQ(maxProfit({5, 2}), 0);
}

TEST(MaxProfitTest, TwoElementsSame) {
    EXPECT_EQ(maxProfit({5, 5}), 0);
}

TEST(MaxProfitTest, Example1) {
    EXPECT_EQ(maxProfit({8, 9, 3, 7, 4, 16, 12}), 13);
}

TEST(MaxProfitTest, Example2Increasing) {
    EXPECT_EQ(maxProfit({1, 2, 3, 4, 5, 6, 7}), 6);
}

TEST(MaxProfitTest, Example3Decreasing) {
    EXPECT_EQ(maxProfit({8, 7, 6, 5, 4, 3, 2}), 0);
}

TEST(MaxProfitTest, AllPricesSame) {
    EXPECT_EQ(maxProfit({5, 5, 5, 5, 5}), 0);
}

TEST(MaxProfitTest, PeakInMiddle) {
    EXPECT_EQ(maxProfit({1, 5, 2, 8}), 7); 
}

TEST(MaxProfitTest, ValleyInMiddleThenHigherPeak) {
    EXPECT_EQ(maxProfit({10, 2, 8, 1, 9}), 8); 
}

TEST(MaxProfitTest, ValleyInMiddleThenLowerPeak) {
    EXPECT_EQ(maxProfit({10, 2, 8, 1, 4}), 6);
}

TEST(MaxProfitTest, NegativePricesProfit) {
    EXPECT_EQ(maxProfit({-2, -5, -1, -3}), 4); 
}

TEST(MaxProfitTest, NegativePricesNoProfit) {
    EXPECT_EQ(maxProfit({-1, -2, -3, -4}), 0);
}

TEST(MaxProfitTest, MixedPrices) {
    EXPECT_EQ(maxProfit({3, 3, 5, 0, 0, 3, 1, 4}), 4);
}

TEST(MaxProfitTest, MinimalCaseProfit) {
    EXPECT_EQ(maxProfit({7,1,5,3,6,4}), 5);
}

TEST(MaxProfitTest, MinimalCaseNoProfit) {
    EXPECT_EQ(maxProfit({7,6,4,3,1}), 0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}