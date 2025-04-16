#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>

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
    if (i >= std::size(arr))
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(arr[i]);
    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);

    return root;
}

// Вспомогательная функция для обхода дерева в глубину (NLR)
void collectPreOrder(TreeNode *root, std::vector<int>& result)
{
    if (!root) 
    {
        return;
    }

    result.push_back(root->data);           // N
    collectPreOrder(root->left, result);    // L
    collectPreOrder(root->right, result);   // R
}


TEST(BuildTreeTest, BasicTest) {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    TreeNode* root = buildTree(input);

    std::vector<int> result;
    collectPreOrder(root, result);
    std::vector<int> expected = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 7};

    EXPECT_EQ(result, expected);
}

TEST(BuildTreeTest, EmptyInput) {
    std::vector<int> input = {};
    TreeNode* root = buildTree(input);
    EXPECT_EQ(root, nullptr);
}

TEST(BuildTreeTest, SingleElement) {
    std::vector<int> input = {42};
    TreeNode* root = buildTree(input);

    std::vector<int> result;
    collectPreOrder(root, result);
    std::vector<int> expected = {42};

    EXPECT_EQ(result, expected);
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}