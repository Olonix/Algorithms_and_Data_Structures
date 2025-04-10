#include <gtest/gtest.h>
#include <iostream>
#include <cstdint>

int binarySearchSqrt(int target)
{
    int32_t l = 0;
    int32_t r = target;
    int64_t middle;

    while (l <= r)
    {
        middle = l + (r - l) / 2;
        if (middle * middle < target)
        {
            l = middle + 1;
            continue;
        }
        if (middle * middle > target)
        {
            r = middle - 1;
            continue;
        }
        return middle;
        
    }
    return r;
}

#ifdef UNIT_TEST

TEST(BinarySearchSqrtTest, PerfectSquares) 
{
    EXPECT_EQ(binarySearchSqrt(4), 2);
    EXPECT_EQ(binarySearchSqrt(9), 3);
    EXPECT_EQ(binarySearchSqrt(16), 4);
}

TEST(BinarySearchSqrtTest, NonPerfectSquares) 
{
    EXPECT_EQ(binarySearchSqrt(8), 2);
    EXPECT_EQ(binarySearchSqrt(10), 3);
}

TEST(BinarySearchSqrtTest, EdgeCases) 
{
    EXPECT_EQ(binarySearchSqrt(0), 0);
    EXPECT_EQ(binarySearchSqrt(1), 1);
    EXPECT_EQ(binarySearchSqrt(2147395599), 46339);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#else

int main()
{
    std::cout << "sqrt(2147395599) = " << binarySearchSqrt(2147395599) << std::endl;
    return 0;
}

#endif // UNIT_TEST