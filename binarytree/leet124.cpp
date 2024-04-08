// 124. Binary Tree Maximum Path Sum

#include "binary_tree.h"
#include <vector>
#include <stack>

int maxPathSum(TreeNode *root, int &MaxValue)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftAns = max(maxPathSum(root->left, MaxValue), 0);
    int rightAns = max(maxPathSum(root->right, MaxValue), 0);

    MaxValue = max(MaxValue, root->val + leftAns + rightAns);

    return root->val + max(leftAns, rightAns);
}
int main()
{
    // TreeNode *root = new TreeNode(-10);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    // TreeNode *root = new TreeNode(9);
    // root->left = new TreeNode(8);
    // root->right = new TreeNode(7);
    // root->left->left = new TreeNode(12);
    // root->left->right = new TreeNode(2);
    // root->right->left = new TreeNode(1);
    // root->right->right = new TreeNode(11);

    TreeNode *root = new TreeNode(-1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-2);

    cout
        << "Binary Tree: ";
    printTree(root);
    cout << endl;

    int MaxValue = INT_MIN;
    maxPathSum(root, MaxValue);
    cout << MaxValue;

    return 0;
}