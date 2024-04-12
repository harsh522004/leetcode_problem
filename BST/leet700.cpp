// Search in a Binary Search Tree
#include "../binarytree/binary_tree.h"
#include <vector>
#include <stack>
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val == val)
    {
        return root;
    }

    if (root->val > val)
    {
        TreeNode *left = searchBST(root->left, val);
        if (left != nullptr)
        {
            return left;
        }
    }
    else
    {
        TreeNode *right = searchBST(root->right, val);
        if (right != nullptr)
        {
            return right;
        }
    }

    return nullptr;
}
int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    cout << searchBST(root, 14)->val;

    return 0;
}