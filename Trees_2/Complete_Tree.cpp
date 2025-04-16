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


bool isCompleteTree(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    
    std::queue<TreeNode*> que;
    TreeNode *node;
    bool seenNull = false;
    que.push(root);

    while (!que.empty())
    {
        node = que.front();
        que.pop();

        if (!node && !seenNull)
        {
            seenNull = true;
            continue;
        }

        if (!node)
        {
            continue;
        }
        

        if (node && seenNull)
        {
            return false;
        }
        
        que.push(node->left);
        que.push(node->right);
    }

    return true;
}



TEST(IsCompleteTreeTest, ValidCompleteTree) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    EXPECT_TRUE(isCompleteTree(root));
}
TEST(IsCompleteTreeTest, IncompleteTree) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7); 

    EXPECT_FALSE(isCompleteTree(root));
}

TEST(IsCompleteTreeTest, FullTree) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    EXPECT_TRUE(isCompleteTree(root));
}

TEST(IsCompleteTreeTest, EmptyTree) {
    EXPECT_TRUE(isCompleteTree(NULL));
}

TEST(IsCompleteTreeTest, SingleNode) {
    TreeNode *root = new TreeNode(1);
    EXPECT_TRUE(isCompleteTree(root));
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}