#include <gtest/gtest.h>
#include <iostream>
#include <vector>
// #include <queue>

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

bool isSymmetric(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    
    std::vector<TreeNode*> que;
    que.push_back(root->left);
    que.push_back(root->right);

    int i;
    size_t len_que;

    while (!que.empty())
    {
        len_que = que.size();
        for (i = 0; i < len_que / 2; i++)
        {
            if (!que[i] && !que[len_que - i - 1])
            {
                continue;
            }
            if (!que[i] || !que[len_que - i - 1])
            {
                return false;
            }
            if (que[i]->data != que[len_que - i - 1]->data)
            {
                return false;
            }

            que.push_back(que[i]->left);
            que.push_back(que[i]->right);
        }

        for (i = len_que / 2; i < len_que; i++)
        {
            if (!que[i])
            {
                continue;
            }
            que.push_back(que[i]->left);
            que.push_back(que[i]->right);
        }
        
        que.erase(que.begin(), que.begin() + len_que);     
    }
    return true;
}


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


TEST(IsSymmetricTest, JustRootAndChildren)
{
    std::vector<int> data = {1, 2, 2};
    TreeNode* root = buildTree(data);
    EXPECT_TRUE(isSymmetric(root));

    std::vector<int> data_1 = {1, 2, 3};
    TreeNode* root_1 = buildTree(data_1);
    EXPECT_FALSE(isSymmetric(root_1));

    std::vector<int> data_2 = {1, 2};
    TreeNode* root_2 = buildTree(data_2);
    EXPECT_FALSE(isSymmetric(root_2));
}

TEST(IsSymmetricTest, SymmetricTree)
{
    std::vector<int> data = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root = buildTree(data);
    EXPECT_TRUE(isSymmetric(root));
}

TEST(IsSymmetricTest, AsymmetricTree1)
{
    std::vector<int> data = {1, 2, 2, 4, 3, 4, 3};
    TreeNode* root = buildTree(data);
    EXPECT_FALSE(isSymmetric(root));

    std::vector<int> data_1 = {1, 2, 2, NULL, 3, NULL, 3};
    TreeNode* root_1 = buildTree(data_1);
    EXPECT_FALSE(isSymmetric(root_1));
}

TEST(IsSymmetricTest, SingleNode)
{
    std::vector<int> data = {1};
    TreeNode* root = buildTree(data);
    EXPECT_TRUE(isSymmetric(root));
}

TEST(IsSymmetricTest, EmptyTree)
{
    TreeNode* root = NULL;
    EXPECT_TRUE(isSymmetric(root));
}


int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}