#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>

int copyTime(int n, int x, int y)
{
    int l = 0;
    int r = (n - 1) * std::max(x, y);
    int middle;

    while (l + 1 < r)
    {
        // std::cout << "l = " << l << "; " << "r = " << r << std::endl;
        middle = l + (r - l) / 2;
        // std::cout << "middle = " << middle << std::endl;
        // std::cout << middle / x << " + " << middle / y << " = " << middle / x + middle / y << std::endl;

        if (middle / x + middle / y < n - 1)
        {
            l = middle;
        }
        else
        {
            r = middle;
        }
        
    }
    return r + std::min(x, y);
}

#ifdef UNIT_TEST

TEST(CopyTimeTest, SingleCopy)
{
    EXPECT_EQ(copyTime(1, 1, 2), 1);
    EXPECT_EQ(copyTime(1, 5, 3), 3);
}

TEST(CopyTimeTest, BasicCases)
{
    EXPECT_EQ(copyTime(4, 1, 2), 3);
    EXPECT_EQ(copyTime(5, 1, 2), 4);
}

TEST(CopyTimeTest, EqualSpeeds)
{
    EXPECT_EQ(copyTime(7, 1, 1), 4);
    EXPECT_EQ(copyTime(6, 1, 1), 4);
    EXPECT_EQ(copyTime(5, 1, 1), 3);
    EXPECT_EQ(copyTime(11, 2, 2), 12);
    EXPECT_EQ(copyTime(10, 2, 2), 12);
    EXPECT_EQ(copyTime(9, 2, 2), 10);
}

TEST(CopyTimeTest, LargerValues)
{
    EXPECT_EQ(copyTime(100, 3, 5), 189);
    EXPECT_EQ(copyTime(39927, 15, 7), 190567);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#else

int main()
{
    std::cout << "n = 100; x = 3; y = 5 -> " << copyTime(100, 3, 5) << std::endl;
    return 0;
}

#endif // UNIT_TEST