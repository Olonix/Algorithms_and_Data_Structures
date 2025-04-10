#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

std::vector<int> shell_sort(std::vector<int> arr)
{
    size_t size_arr = std::size(arr);
    int gap = size_arr / 2;
    int current_position;
    int m_gap;

    while (gap > 0)
    {
        for (current_position = 0; current_position < size_arr; current_position++)
        {
            m_gap = current_position;
            while (m_gap >= gap && arr[m_gap] < arr[m_gap - gap])
            {
                std::swap(arr[m_gap - gap], arr[m_gap]);
                m_gap -= gap;
            }
            
        }
        gap = gap / 2;
        
    }

    return arr;
}


TEST(ShellSortTest, EmptyVector) {
    std::vector<int> arr = {};
    std::vector<int> sorted = shell_sort(arr);
    EXPECT_TRUE(sorted.empty());
}

TEST(ShellSortTest, SingleElement) {
    std::vector<int> arr = {42};
    std::vector<int> sorted = shell_sort(arr);
    EXPECT_EQ(sorted[0], 42);
}

TEST(ShellSortTest, AlreadySorted) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> sorted = shell_sort(arr);
    EXPECT_EQ(sorted, expected);
}

TEST(ShellSortTest, ReverseSorted) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> sorted = shell_sort(arr);
    EXPECT_EQ(sorted, expected);
}

TEST(ShellSortTest, Duplicates) {
    std::vector<int> arr = {2, 3, 2, 1, 3, 1};
    std::vector<int> expected = {1, 1, 2, 2, 3, 3};
    std::vector<int> sorted = shell_sort(arr);
    EXPECT_EQ(sorted, expected);
}

TEST(ShellSortTest, RandomOrder) {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::vector<int> expected = {1, 1, 2, 3, 4, 5, 5, 6, 9};
    std::vector<int> sorted = shell_sort(arr);
    EXPECT_EQ(sorted, expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}