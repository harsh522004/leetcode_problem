// 104 Max depth of binary tree

#include "binary_tree.h"
#include <vector>
#include <queue>
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
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(8);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    int ans = maxDepth(root);
    cout << ans << " ";

    return 0;
}