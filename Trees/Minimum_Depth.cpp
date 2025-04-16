#include <gtest/gtest.h>
#include <iostream>
#include <vector>

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


int minDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 1;
    }
    if (root->left && root->right)
    {
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
    if (root->left)
    {
        return 1 + minDepth(root->left);
    }
    
    return 1 + minDepth(root->right);
}


TEST(MinDepthTest, EmptyTree)
{
    TreeNode* root = NULL;
    EXPECT_EQ(minDepth(root), 0);
}

TEST(MinDepthTest, SingleNode)
{
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(minDepth(root), 1);
}

TEST(MinDepthTest, TwoLevelsFull)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    EXPECT_EQ(minDepth(root), 2);
}

TEST(MinDepthTest, LeftSided)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    EXPECT_EQ(minDepth(root), 3);
}

TEST(MinDepthTest, RightSided)
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    EXPECT_EQ(minDepth(root), 3);
}

TEST(MinDepthTest, AsymmetricMinimum)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    EXPECT_EQ(minDepth(root), 2);
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}