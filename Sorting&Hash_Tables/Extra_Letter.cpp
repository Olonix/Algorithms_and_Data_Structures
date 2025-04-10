#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <string>

std::string extraLetter(std::string& a, std::string& b)
{
    std::unordered_map<char, int> hashMapA;

    for (char c : a)
    {
        hashMapA[c]++;
    }

    for (char c : b)
    {
        if (hashMapA[c])
        // if (hashMapA.count(c) > 0)
        {
            hashMapA[c]--;
            // if (hashMapA[c] == 0)
            // {
            //     hashMapA.erase(c);
            // }
            continue;
        }
        return std::string(1, c);
    }

    return "";
}

#ifdef UNIT_TEST


TEST(ExtraLetterTest, ExtraMiddle)
{
    std::string a = "uio";
    std::string b = "oeiu";
    EXPECT_EQ(extraLetter(a, b), "e");
}

TEST(ExtraLetterTest, ExtraAtEdge)
{
    std::string a = "world";
    std::string b = "sworld";
    EXPECT_EQ(extraLetter(a, b), "s");

    std::string a_1 = "fe";
    std::string b_1 = "efo";
    EXPECT_EQ(extraLetter(a_1, b_1), "o");
}

TEST(ExtraLetterTest, ExtraRepeat)
{
    std::string a = "hello";
    std::string b = "helloo";
    EXPECT_EQ(extraLetter(a, b), "o");

    std::string a_1 = "bbb";
    std::string b_1 = "bbbb";
    EXPECT_EQ(extraLetter(a_1, b_1), "b");
}

TEST(ExtraLetterTest, NoExtraLetter)
{
    std::string a = "test";
    std::string b = "test";
    EXPECT_EQ(extraLetter(a, b), "");

    std::string a_1 = "ab";
    std::string b_1 = "ab";
    EXPECT_EQ(extraLetter(a_1, b_1), "");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#else

int main()
{
    std::string a = "uio";
    std::string b = "oeiu";
    std::cout << "a = 'uio'; b = 'oeiu' -> " << extraLetter(a, b) << std::endl;
    return 0;
}

#endif // UNIT_TEST