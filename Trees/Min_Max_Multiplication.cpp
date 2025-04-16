#include <gtest/gtest.h>
#include <iostream>
#include <vector>

// предположим, что бинарное дерево поиска восстанавливается из данного массива с помощью функции buildTree() (но здесь она не будет использоваться)
// т. е. полное бинарное дерево поиска
int maxMinMultiplication(std::vector<int>& arr)
{
    if (arr.size() < 2)
    {
        return -1;
    }
    if (arr.size() == 2)
    {
        return arr[0] * arr[1];
    }

    int min_index = 1;
    int max_index = 2;
    int i;
    size_t len_arr = arr.size();
    
    for (i = 0; i < len_arr; i = 2 * i + 1)
    {
        min_index = i;
    }

    for (i = 0; i < len_arr; i = 2 * i + 2)
    {
        max_index = i;
    }

    return arr[min_index] * arr[max_index];    
}



TEST(MaxMinMultiplicationTest, BasicCases)
{
    std::vector<int> tree_1 = {5, 3, 8, 1, 4, 7, 9};
    EXPECT_EQ(maxMinMultiplication(tree_1), 1 * 9);

    std::vector<int> tree_2 = {10, 5, 20};
    EXPECT_EQ(maxMinMultiplication(tree_2), 5 * 20);

    std::vector<int> tree_3 = {6, 2, 10, 1, 4, 8, 12};
    EXPECT_EQ(maxMinMultiplication(tree_3), 1 * 12);
}

TEST(MaxMinMultiplicationTest, SmallCases)
{
    std::vector<int> tree_1 = {2};
    EXPECT_EQ(maxMinMultiplication(tree_1), -1);

    std::vector<int> tree_2 = {2, 3};
    EXPECT_EQ(maxMinMultiplication(tree_2), 6);
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}