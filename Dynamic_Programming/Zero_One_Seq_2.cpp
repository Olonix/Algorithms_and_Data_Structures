#include <vector>

long long count_sequences(int n) {
    if (n < 0) {
        return 0;
    }

    std::vector<long long> dp;
    dp.push_back(1); 
    dp.push_back(2); 
    dp.push_back(4); 

    for (int i = 3; i <= n; ++i) {
        dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
    }
    
    return dp[n];
}

#include "gtest/gtest.h"

TEST(CountSequencesTest, NegativeN) {
    EXPECT_EQ(count_sequences(-1), 0);
    EXPECT_EQ(count_sequences(-10), 0);
}

TEST(CountSequencesTest, ZeroLength) {
    EXPECT_EQ(count_sequences(0), 1);
}

TEST(CountSequencesTest, LengthOne) {
    EXPECT_EQ(count_sequences(1), 2);
}

TEST(CountSequencesTest, LengthTwo) {
    EXPECT_EQ(count_sequences(2), 4);
}

TEST(CountSequencesTest, LengthThree) {
    EXPECT_EQ(count_sequences(3), 7);
}

TEST(CountSequencesTest, LengthFour) {
    EXPECT_EQ(count_sequences(4), 13);
}

TEST(CountSequencesTest, LengthFive) {
    EXPECT_EQ(count_sequences(5), 24);
}

TEST(CountSequencesTest, LargerN) {
    EXPECT_EQ(count_sequences(10), 504);
    EXPECT_EQ(count_sequences(20), 223317);
}

TEST(CountSequencesTest, MaxIntRangeN) {
    EXPECT_EQ(count_sequences(30), 98950096);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}