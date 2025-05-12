#include <vector>

std::vector<std::vector<long long>> generatePascalsTriangle(int n) {
    if (n <= 0) {
        return {};
    }

    std::vector<std::vector<long long>> pascalTriangle;
    
    for (int i = 0; i < n; i++) {
        pascalTriangle.push_back(std::vector<long long>(i + 1, 1));
    }

    for (int row_idx = 1; row_idx < n; row_idx++) {
        for (int col_idx = 1; col_idx < row_idx; col_idx++) {
            pascalTriangle[row_idx][col_idx] = pascalTriangle[row_idx - 1][col_idx - 1] + pascalTriangle[row_idx - 1][col_idx];
        }
    }

    return pascalTriangle;
}

#include "gtest/gtest.h"

TEST(PascalsTriangleTest, ZeroRows) {
    std::vector<std::vector<long long>> expected = {};
    EXPECT_EQ(generatePascalsTriangle(0), expected);
}

TEST(PascalsTriangleTest, OneRow) {
    std::vector<std::vector<long long>> expected = {{1}};
    EXPECT_EQ(generatePascalsTriangle(1), expected);
}

TEST(PascalsTriangleTest, TwoRows) {
    std::vector<std::vector<long long>> expected = {{1}, {1, 1}};
    EXPECT_EQ(generatePascalsTriangle(2), expected);
}

TEST(PascalsTriangleTest, ThreeRows) {
    std::vector<std::vector<long long>> expected = {{1}, {1, 1}, {1, 2, 1}};
    EXPECT_EQ(generatePascalsTriangle(3), expected);
}

TEST(PascalsTriangleTest, SixRows) {
    std::vector<std::vector<long long>> expected = {
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1},
        {1, 5, 10, 10, 5, 1}
    };
    EXPECT_EQ(generatePascalsTriangle(6), expected);
}

TEST(PascalsTriangleTest, NegativeInput) {
    std::vector<std::vector<long long>> expected = {};
    EXPECT_EQ(generatePascalsTriangle(-5), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}