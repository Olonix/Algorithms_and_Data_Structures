#include <string>
#include <vector>
#include <algorithm>

std::string longestPalindrome(const std::string& s) {
    int n = s.length();
    if (n == 0) {
        return "";
    }
    if (n == 1) {
        return s;
    }

    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    int start_index = 0;
    int maxLength = 1;

    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            if (maxLength < 2) {
                start_index = i;
                maxLength = 2;
            }
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if (len > maxLength) {
                    start_index = i;
                    maxLength = len;
                }
            }
        }
    }

    return s.substr(start_index, maxLength);
}

#include "gtest/gtest.h"

TEST(LongestPalindromeTest, EmptyString) {
    EXPECT_EQ(longestPalindrome(""), "");
}

TEST(LongestPalindromeTest, SingleCharacter) {
    EXPECT_EQ(longestPalindrome("a"), "a");
    EXPECT_EQ(longestPalindrome("z"), "z");
}

TEST(LongestPalindromeTest, ExampleBabad) {
    std::string result = longestPalindrome("babad");
    EXPECT_TRUE(result == "bab" || result == "aba");
}

TEST(LongestPalindromeTest, ExampleCbbd) {
    EXPECT_EQ(longestPalindrome("cbbd"), "bb");
}

TEST(LongestPalindromeTest, AllSameCharacters) {
    EXPECT_EQ(longestPalindrome("aaa"), "aaa");
    EXPECT_EQ(longestPalindrome("bbbbb"), "bbbbb");
}

TEST(LongestPalindromeTest, NoPalindromeLongerThanOne) {
    std::string result = longestPalindrome("abcde");
    EXPECT_EQ(result.length(), 1);
    EXPECT_TRUE(result == "a" || result == "b" || result == "c" || result == "d" || result == "e");
}

TEST(LongestPalindromeTest, EvenLengthPalindrome) {
    EXPECT_EQ(longestPalindrome("abba"), "abba");
    EXPECT_EQ(longestPalindrome("noon"), "noon");
}

TEST(LongestPalindromeTest, OddLengthPalindrome) {
    EXPECT_EQ(longestPalindrome("racecar"), "racecar");
    EXPECT_EQ(longestPalindrome("madam"), "madam");
}

TEST(LongestPalindromeTest, PalindromeAtBeginning) {
    EXPECT_EQ(longestPalindrome("abacaba_xyz"), "abacaba");
}

TEST(LongestPalindromeTest, PalindromeAtEnd) {
    EXPECT_EQ(longestPalindrome("xyz_abacaba"), "abacaba");
}

TEST(LongestPalindromeTest, PalindromeInMiddle) {
    EXPECT_EQ(longestPalindrome("xy_abacaba_z"), "_abacaba_");
}

TEST(LongestPalindromeTest, LongerExampleBananas) {
    EXPECT_EQ(longestPalindrome("bananas"), "anana");
}

TEST(LongestPalindromeTest, ComplexCase1) {
    EXPECT_EQ(longestPalindrome("forgeeksskeegfor"), "geeksskeeg");
}

TEST(LongestPalindromeTest, ComplexCase2) {
    std::string result = longestPalindrome("abacdfgdcaba");
    EXPECT_TRUE(result == "aba" || result == "aca" || result == "cdc");
    EXPECT_EQ(longestPalindrome("abacdfgdcaba"), "aba"); 
}


TEST(LongestPalindromeTest, StringWithNumbers) {
    EXPECT_EQ(longestPalindrome("a12321b"), "12321");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}