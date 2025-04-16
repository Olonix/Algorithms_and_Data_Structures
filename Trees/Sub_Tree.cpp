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

// q - поддерево p?
bool isSubTree(TreeNode *p, TreeNode *q)
{
    if (!q)
    {
        return true;
    }
    if (!p)
    {
        return false;
    }
    if (isSameTree(p, q))
    {
        return true;
    }

    return isSubTree(p->left, q) || isSubTree(p->right, q);
}


TEST(IsSubTreeTest, NullSubtree) {
    TreeNode *p = new TreeNode(1);
    EXPECT_TRUE(isSubTree(p, NULL));
}

TEST(IsSubTreeTest, SubtreeIsNullRoot) {
    EXPECT_TRUE(isSubTree(NULL, NULL));
}

TEST(IsSubTreeTest, NullRootNonNullSubtree) {
    TreeNode *q = new TreeNode(1);
    EXPECT_FALSE(isSubTree(NULL, q));
}

TEST(IsSubTreeTest, ExactMatch) {
    TreeNode *p = new TreeNode(1, 
                        new TreeNode(2), 
                        new TreeNode(3));
    TreeNode *q = new TreeNode(1, 
                        new TreeNode(2), 
                        new TreeNode(3));
    EXPECT_TRUE(isSubTree(p, q));
}

TEST(IsSubTreeTest, IsRealSubtree) {
    TreeNode *p = new TreeNode(1,
                        new TreeNode(2,
                            new TreeNode(4),
                            new TreeNode(5)),
                        new TreeNode(3));
    TreeNode *q = new TreeNode(2, 
                        new TreeNode(4), 
                        new TreeNode(5));
    EXPECT_TRUE(isSubTree(p, q));
}

TEST(IsSubTreeTest, NotASubtree) {
    TreeNode *p = new TreeNode(1,
                        new TreeNode(2),
                        new TreeNode(3));
    TreeNode *q = new TreeNode(2, 
                        new TreeNode(4),
                        NULL);
    EXPECT_FALSE(isSubTree(p, q));
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}