#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>

class TreeNode
{
    public:
        int data;
        int balanceFactor;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val = 0, int balanceFactor = 0, TreeNode *left = NULL, TreeNode *right = NULL)
        {
            data = val;
            this->balanceFactor = balanceFactor;
            this->left = left;
            this->right = right;
        }
};


int calculateHeightsAndBalance(TreeNode *root)
{
    if (!root) 
    {
        return 0;
    }

    int leftHeight = calculateHeightsAndBalance(root->left);
    int rightHeight = calculateHeightsAndBalance (root->right);
    root->balanceFactor = leftHeight - rightHeight ;

    return 1 + std::max(leftHeight, rightHeight);
}


TEST(CalculateHeightsAndBalanceTest, SingleNode) 
{
    TreeNode* root = new TreeNode(10);
    calculateHeightsAndBalance(root);
    EXPECT_EQ(root->balanceFactor, 0);
}

TEST(CalculateHeightsAndBalanceTest, BalancedTree) 
{
    TreeNode* left = new TreeNode(5);
    TreeNode* right = new TreeNode(15);
    TreeNode* root = new TreeNode(10, 0, left, right);

    calculateHeightsAndBalance(root);

    EXPECT_EQ(root->balanceFactor, 0);
    EXPECT_EQ(left->balanceFactor, 0);
    EXPECT_EQ(right->balanceFactor, 0);
}

TEST(CalculateHeightsAndBalanceTest, LeftTree) 
{
    TreeNode* leftChild = new TreeNode(5, 0, new TreeNode(3), NULL);
    TreeNode* root = new TreeNode(10, 0, leftChild, NULL);

    calculateHeightsAndBalance(root);

    EXPECT_EQ(root->balanceFactor, 2);
    EXPECT_EQ(leftChild->balanceFactor, 1);
    EXPECT_EQ(leftChild->left->balanceFactor, 0);
}

TEST(CalculateHeightsAndBalanceTest, RightTree) 
{
    TreeNode* rightChild = new TreeNode(20, 0, NULL, new TreeNode(25));
    TreeNode* root = new TreeNode(10, 0, NULL, rightChild);

    calculateHeightsAndBalance(root);

    EXPECT_EQ(root->balanceFactor, -2);
    EXPECT_EQ(rightChild->balanceFactor, -1);
    EXPECT_EQ(rightChild->right->balanceFactor, 0);
}

TEST(CalculateHeightsAndBalanceTest, FullTree) 
{
    TreeNode* l = new TreeNode(2);
    TreeNode* r = new TreeNode(4);
    TreeNode* lRoot = new TreeNode(3, 0, l, r);

    TreeNode* l2 = new TreeNode(6);
    TreeNode* r2 = new TreeNode(8);
    TreeNode* rRoot = new TreeNode(7, 0, l2, r2);

    TreeNode* root = new TreeNode(5, 0, lRoot, rRoot);

    calculateHeightsAndBalance(root);

    EXPECT_EQ(root->balanceFactor, 0);
    EXPECT_EQ(lRoot->balanceFactor, 0);
    EXPECT_EQ(rRoot->balanceFactor, 0);
    EXPECT_EQ(l->balanceFactor, 0);
    EXPECT_EQ(r->balanceFactor, 0);
    EXPECT_EQ(l2->balanceFactor, 0);
    EXPECT_EQ(r2->balanceFactor, 0);
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}