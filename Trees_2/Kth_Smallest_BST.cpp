#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <stack>

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


TreeNode *buildTree(std::vector<int>& arr, int i = 0)
{
    if (i >= std::size(arr) || arr[i] == -1)  // -1 обозначает NULL
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);

    return root;
}


int kthSmallest(TreeNode *root, int k)
{
    std::stack<TreeNode*> minNodes;
    TreeNode *current = root;
    int counter = 0;

    while (minNodes.size() || current)
    {
        while (current)
        {
            minNodes.push(current);
            current = current->left;
        }
        
        current = minNodes.top();
        minNodes.pop();
        counter++;

        if (counter == k)
        {
            return current->data;
        }

        current = current->right;        
    }

    return -1; 
}


TEST(KthSmallestTest, BasicBalancedTree) 
{
    std::vector<int> arr_1 = {5, 3, 6, -1, 4};
    TreeNode* root_1 = buildTree(arr_1);

    EXPECT_EQ(kthSmallest(root_1, 1), 3);
    EXPECT_EQ(kthSmallest(root_1, 2), 4);
    EXPECT_EQ(kthSmallest(root_1, 3), 5);
    EXPECT_EQ(kthSmallest(root_1, 4), 6);

    std::vector<int> arr_2 = {5, 3, 6, 2, 4, -1, -1, 1};
    TreeNode* root_2 = buildTree(arr_2);
    
    EXPECT_EQ(kthSmallest(root_2, 1), 1);
    EXPECT_EQ(kthSmallest(root_2, 2), 2);
    EXPECT_EQ(kthSmallest(root_2, 3), 3);
    EXPECT_EQ(kthSmallest(root_2, 4), 4);
    EXPECT_EQ(kthSmallest(root_2, 5), 5);
    EXPECT_EQ(kthSmallest(root_2, 6), 6);
}

TEST(KthSmallestTest, SingleElementTree) 
{
    std::vector<int> arr = {42};
    TreeNode* root = buildTree(arr);

    EXPECT_EQ(kthSmallest(root, 1), 42);
}

TEST(KthSmallestTest, EmptyTree) 
{
    TreeNode* root = NULL;

    EXPECT_EQ(kthSmallest(root, 1), -1);
}

TEST(KthSmallestTest, LeftSkewedTree) 
{
    std::vector<int> arr = {5, 
                            4, -1, 
                            3, -1, -1, -1,
                            2, -1, -1, -1, -1, -1, -1, -1, 
                            1};
    TreeNode* root = buildTree(arr);

    EXPECT_EQ(kthSmallest(root, 1), 1);
    EXPECT_EQ(kthSmallest(root, 5), 5);
}

TEST(KthSmallestTest, RightSkewedTree)
{
    std::vector<int> arr = {1, 
                            -1, 2, 
                            -1, -1, -1, 3, 
                            -1, -1, -1, -1, -1, -1, -1, -4, 
                            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5};
    TreeNode* root = buildTree(arr);

    EXPECT_EQ(kthSmallest(root, 1), 1);
    EXPECT_EQ(kthSmallest(root, 3), 3);
    EXPECT_EQ(kthSmallest(root, 5), 5);
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}