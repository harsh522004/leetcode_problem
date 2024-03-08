// 543. Diameter of Binary Tree

#include "binary_tree.h"
#include <vector>
#include <stack>
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0; // or 1 may be
    }

    int left = maxDepth(root->left); // here add 1 maybe
    int right = maxDepth(root->right);

    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return left + right + 1;
}

// <height , max Daimeter>
pair<int, int> Harsh(TreeNode *node)
{
    if (node == nullptr)
    {
        return make_pair(0, 0);
    }

    pair<int, int> left = Harsh(node->left);
    pair<int, int> right = Harsh(node->right);

    int height = max(left.first, right.first) + 1;
    int newDaimeter = (left.first + right.first); // may be add 1
    int maxDaimeter = max(left.second, max(right.second, newDaimeter));

    return make_pair(height, maxDaimeter);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(6);

    root->left->right->right = new TreeNode(8);

    // tree 2

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    pair<int, int> ans = Harsh(root);
    cout << ans.second;
    // int ans = diameterOfBinaryTree(root);
    // cout << ans;

    return 0;
}