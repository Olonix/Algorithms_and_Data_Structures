#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>


class TreeNode
{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val = 0, TreeNode *left = NULL, TreeNode *right = NULL)
        {
            data = val;
            this->left = left;
            this->right = right;
        }
};


using Elem = std::tuple<int, int, int>;

std::vector<int> mergeKSortedArrays(std::vector<std::vector<int>>& sortedArrays)
{
    std::vector<int> mergedArray;
    std::priority_queue<Elem, std::vector<Elem>, std::greater<Elem>> minHeap;
    int i = 0;
    int value;
    int arrayIdx;
    int elementIdx;

    for (std::vector<int> array : sortedArrays)
    {
        if (array.size())
        {
            minHeap.push(Elem {array[0], i, 0});
        }
        i++;
    }

    while (!minHeap.empty())
    {
        auto [value, arrayIdx, elementIdx] = minHeap.top();
        minHeap.pop();
        mergedArray.push_back(value);

        if (elementIdx + 1 < sortedArrays[arrayIdx].size())
        {
            minHeap.push(Elem {sortedArrays[arrayIdx][elementIdx + 1], arrayIdx, elementIdx + 1});
        }
        
    }
    
    return mergedArray;
}


TEST(MergeKSortedArraysTest, BasicInput) {
    std::vector<std::vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, WithDuplicates) {
    std::vector<std::vector<int>> arrays = {
        {1, 2, 2},
        {2, 2, 3, 4},
        {0, 5}
    };
    std::vector<int> expected = {0, 1, 2, 2, 2, 2, 3, 4, 5};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, NegativeNum) {
    std::vector<std::vector<int>> arrays = {
        {-10, -5, 0},
        {-3, 1, 4},
        {-6, -2, 3}
    };
    std::vector<int> expected = {-10, -6, -5, -3, -2, 0, 1, 3, 4};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, AllEmpty) {
    std::vector<std::vector<int>> arrays = {
        {}, {}, {}
    };
    std::vector<int> expected = {};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, SingleNonEmpty) {
    std::vector<std::vector<int>> arrays = {
        {}, {1, 2, 3}, {}
    };
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, SingleElement) {
    std::vector<std::vector<int>> arrays = {
        {42}
    };
    std::vector<int> expected = {42};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, NoArrays) {
    std::vector<std::vector<int>> arrays = {};
    std::vector<int> expected = {};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}

TEST(MergeKSortedArraysTest, AllSameElements) {
    std::vector<std::vector<int>> arrays = {
        {1, 1, 1},
        {1, 1},
        {1}
    };
    std::vector<int> expected = {1, 1, 1, 1, 1, 1};
    EXPECT_EQ(mergeKSortedArrays(arrays), expected);
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}