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

int dfs(TreeNode *left, TreeNode *right)
{
    if (!left || !right)
    {
        return 0;
    }

    if (left->data == right->data)
    {
        return dfs(left->left, right->right) + dfs(left->right, right->left) + 1;
    }

    return dfs(left->left, right->right) + dfs(left->right, right->left);
}

int CountMirrorTwins(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    return dfs(root->left, root->right);
}


TEST(CountMirrorTwinsTest, EmptyTree) {
    TreeNode* root = nullptr;
    EXPECT_EQ(CountMirrorTwins(root), 0);
}

TEST(CountMirrorTwinsTest, SingleNodeTree) {
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(CountMirrorTwins(root), 0);
}

TEST(CountMirrorTwinsTest, PerfectMirrorTree) {
    TreeNode* root = new TreeNode(3,
                            new TreeNode(9,
                                new TreeNode(6),
                                new TreeNode(8)),
                            new TreeNode(9,
                                new TreeNode(8),
                                new TreeNode(6)));

    EXPECT_EQ(CountMirrorTwins(root), 3);
}

TEST(CountMirrorTwinsTest, AsymmetricValues) {
    TreeNode* root_1 = new TreeNode(3,
                            new TreeNode(9,
                                new TreeNode(6),
                                NULL),
                            new TreeNode(9,
                                new TreeNode(6),
                                NULL));

    EXPECT_EQ(CountMirrorTwins(root_1), 1);

    TreeNode* root_2 = new TreeNode(1,
                            new TreeNode(2,
                                new TreeNode(3),
                                new TreeNode(5)),
                            new TreeNode(2,
                                new TreeNode(4),
                                new TreeNode(3)));

    EXPECT_EQ(CountMirrorTwins(root_2), 2);
}

TEST(CountMirrorTwinsTest, NoMirrorTwins) {
    TreeNode* root = new TreeNode(1,
                            new TreeNode(2),
                            new TreeNode(3));
    EXPECT_EQ(CountMirrorTwins(root), 0);
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}