// 105. Construct Binary Tree from Preorder and Inorder Traversal

#include "binary_tree.h"
#include <vector>
#include <queue>
#include <cmath>
TreeNode *function(vector<int> &preorder, int value, vector<int> tamp)
{
    if (tamp.size() == 0)
    {
        return nullptr;
    }
    if (tamp.size() == 1)
    {
        TreeNode *node = new TreeNode(tamp[0]);
        return node;
    }

    // create left vector
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
}

int main()
{

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    // root->left->left->right = new TreeNode(8);

    vector<int> preorder = {1, 2, 8, 3, 9, 6, 4};
    vector<int> inorder = {8, 2, 1, 9, 3, 4, 6};
    TreeNode *root = buildTree(preorder, inorder);
    cout << root->val << endl;

    return 0;
}