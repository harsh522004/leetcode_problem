// 987. Vertical Order Traversal of a Binary Tree

#include "binary_tree.h"
#include <vector>
#include <stack>
int maxWidth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int count = 1;

    while (root != nullptr)
    {
        count--;
        root = root->left;
    }

    return count;
}
void DFS(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    DFS(root->left);
    cout << root->val << " ";
    DFS(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    // DFS(root);
    cout << maxWidth(root);

    return 0;
}