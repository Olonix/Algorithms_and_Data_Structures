#include <vector>

long long b_sequences(int n) {
    if (n < 0) {
        return 0; 
    }

    std::vector<long long> dp;
    dp.push_back(1); 
    dp.push_back(2); 

    for (int i = 2; i <= n; ++i) {
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }
    
    return dp[n];
}

#include "gtest/gtest.h"

TEST(BSequencesTest, NegativeN) {
    EXPECT_EQ(b_sequences(-1), 0);
    EXPECT_EQ(b_sequences(-5), 0);
}

TEST(BSequencesTest, ZeroLength) {
    EXPECT_EQ(b_sequences(0), 1);
}

TEST(BSequencesTest, LengthOne) {
    EXPECT_EQ(b_sequences(1), 2);
}

TEST(BSequencesTest, LengthTwo) {
    EXPECT_EQ(b_sequences(2), 3);
}

TEST(BSequencesTest, LengthThree) {
    EXPECT_EQ(b_sequences(3), 5);
}

TEST(BSequencesTest, LargeN) {
    EXPECT_EQ(b_sequences(4), 8);
    EXPECT_EQ(b_sequences(5), 13);
    EXPECT_EQ(b_sequences(10), 144);
}

TEST(BSequencesTest, MaxIntRangeN) {
    EXPECT_EQ(b_sequences(45), 2971215073LL);
    EXPECT_EQ(b_sequences(46), 4807526976LL);
}

TEST(BSequencesTest, VeryLargeN) {
    EXPECT_EQ(b_sequences(90), 7540113804746346429LL);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
