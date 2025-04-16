#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <queue>

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


TreeNode *mirrorTreeIterative(TreeNode *root) 
{
    if (!root) 
    {
        return NULL;
    }

    std::queue<TreeNode*> que;
    que.push(root);
    TreeNode *current;
    TreeNode *temp;

    while (que.size() > 0) 
    {
        current = que.front();
        que.pop();
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        if (current->left) {
            que.push(current->left);
        }
        if (current->right) {
            que.push(current->right);
        }
    }
    return root;
}


TEST(MirrorTreeIterativeTest, NullTree) {
    TreeNode* root = NULL;
    TreeNode* mirrored = mirrorTreeIterative(root);
    EXPECT_EQ(mirrored, nullptr);
}

TEST(MirrorTreeIterativeTest, SingleNodeTree) {
    TreeNode* root = new TreeNode(1);
    TreeNode* mirrored = mirrorTreeIterative(root);
    EXPECT_EQ(mirrored->data, 1);
    EXPECT_EQ(mirrored->left, nullptr);
    EXPECT_EQ(mirrored->right, nullptr);
}

TEST(MirrorTreeIterativeTest, TwoLevelTree) {
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    TreeNode* root = new TreeNode(1, left, right);

    TreeNode* mirrored = mirrorTreeIterative(root);

    EXPECT_EQ(mirrored->left->data, 3);
    EXPECT_EQ(mirrored->right->data, 2);
}

TEST(MirrorTreeIterativeTest, ThreeLevelTree) {
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(2, n4, NULL);
    TreeNode* n3 = new TreeNode(3, NULL, n5);
    TreeNode* root = new TreeNode(1, n2, n3);

    TreeNode* mirrored = mirrorTreeIterative(root);

    EXPECT_EQ(mirrored->left->data, 3);
    EXPECT_EQ(mirrored->right->data, 2);
    EXPECT_EQ(mirrored->left->left->data, 5);
    EXPECT_EQ(mirrored->right->right->data, 4);
}

TEST(MirrorTreeIterativeTest, MirroredBack) {
    TreeNode* l = new TreeNode(2);
    TreeNode* r = new TreeNode(3);
    TreeNode* root = new TreeNode(1, l, r);

    TreeNode* mirrored = mirrorTreeIterative(root);
    TreeNode* backToOriginal = mirrorTreeIterative(mirrored);

    EXPECT_EQ(backToOriginal->left->data, 2);
    EXPECT_EQ(backToOriginal->right->data, 3);
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}