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


bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
    {
        return true;
    }
    if (!p || !q)
    {
        return false;
    }
    if (p->data != q->data)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


TEST(IsSameTreeTest, BothNull) {
    EXPECT_TRUE(isSameTree(NULL, NULL));
}

TEST(IsSameTreeTest, OneNull) {
    TreeNode *node = new TreeNode(1);
    EXPECT_FALSE(isSameTree(node, NULL));
    EXPECT_FALSE(isSameTree(NULL, node));
}

TEST(IsSameTreeTest, IdenticalTrees) {
    TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    EXPECT_TRUE(isSameTree(p, q));
}

TEST(IsSameTreeTest, DifferentStructure) {
    TreeNode *p = new TreeNode(1, new TreeNode(2), NULL);
    TreeNode *q = new TreeNode(1, NULL, new TreeNode(2));
    EXPECT_FALSE(isSameTree(p, q));
}

TEST(IsSameTreeTest, DifferentValues) {
    TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode *q = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    EXPECT_FALSE(isSameTree(p, q));
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}