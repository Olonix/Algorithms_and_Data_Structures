#include <gtest/gtest.h>
#include <iostream>
#include <vector>

bool isMaxHeap(std::vector<int>& arr)
{
    int n = arr.size();    
    int i;
    int left;
    int right;

    for (i = 0; i <= (n - 2) / 2; i++)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < n && arr[i] < arr[left])
        {
            return false;
        }
        if (right < n && arr[i] < arr[right])
        {
            return false;
        }
        
    }
    
    return true;
}


TEST(MaxHeapTest, ValidHeap) {
    std::vector<int> heap = {10, 8, 9, 7, 6, 5, 5};
    EXPECT_TRUE(isMaxHeap(heap));
}

TEST(MaxHeapTest, ChildGreaterThanParent) {
    std::vector<int> heap_1 = {10, 15, 9, 7, 6, 5, 5};
    EXPECT_FALSE(isMaxHeap(heap_1));

    std::vector<int> heap_2 = {10, 9, 8, 7, 6, 5, 11};
    EXPECT_FALSE(isMaxHeap(heap_2));
}

TEST(MaxHeapTest, EmptyHeap) {
    std::vector<int> heap = {};
    EXPECT_TRUE(isMaxHeap(heap));
}

TEST(MaxHeapTest, OneElement) {
    std::vector<int> heap = {42};
    EXPECT_TRUE(isMaxHeap(heap));
}

TEST(MaxHeapTest, EqualElements) {
    std::vector<int> heap = {5, 5, 5, 5};
    EXPECT_TRUE(isMaxHeap(heap));
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}