#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> hashMapAnagram;
    std::string sorted;
    std::vector<std::vector<std::string>> answer;

    for (std::string str : strs)
    {
        sorted = str;
        std::sort(sorted.begin(), sorted.end());
        hashMapAnagram[sorted].push_back(str);
    }
    
    for (auto& [key, group] : hashMapAnagram)
    {
        answer.push_back(group);
    }

    return answer;
}


void make_one_view(std::vector<std::vector<std::string>>& groups)
{
    for (auto& group : groups)
    {
        std::sort(group.begin(), group.end());
    }
    std::sort(groups.begin(), groups.end(), [](std::vector<std::string>& a, std::vector<std::string>& b) 
    {
        return a[0] < b[0];
    });
}


TEST(GroupAnagramsTest, ClassicExample)
{
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> expected = {
        {"ate", "eat", "tea"},
        {"nat", "tan"},
        {"bat"}
    };

    auto result = groupAnagrams(input);

    make_one_view(result);
    make_one_view(expected);

    EXPECT_EQ(result, expected);
}

TEST(GroupAnagramsTest, SingleElement)
{
    std::vector<std::string> input = {"a"};
    std::vector<std::vector<std::string>> expected = {
        {"a"}
    };

    auto result = groupAnagrams(input);

    make_one_view(result);
    make_one_view(expected);

    EXPECT_EQ(result, expected);
}

TEST(GroupAnagramsTest, EmptyInput)
{
    std::vector<std::string> input = {};
    auto result = groupAnagrams(input);
    EXPECT_TRUE(result.empty());
}

TEST(GroupAnagramsTest, AllAnagrams)
{
    std::vector<std::string> input = {"abc", "cab", "bca", "cba"};
    std::vector<std::vector<std::string>> expected = {
        {"abc", "bca", "cab", "cba"}
    };

    auto result = groupAnagrams(input);
    make_one_view(result);
    make_one_view(expected);

    EXPECT_EQ(result, expected);
}

TEST(GroupAnagramsTest, RepeatLetters)
{
    std::vector<std::string> input = {"won", "now", "aaa", "ooo", "ooo"};
    std::vector<std::vector<std::string>> expected = {
        {"aaa"},
        {"ooo", "ooo"},
        {"won", "now"}
    };

    auto result = groupAnagrams(input);

    make_one_view(result);
    make_one_view(expected);

    EXPECT_EQ(result, expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}