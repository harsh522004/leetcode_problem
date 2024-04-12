//  Insert into a Binary Search Tree

#include "../binarytree/binary_tree.h"
#include <vector>
#include <stack>
TreeNode *insertIntoBST(TreeNode *current, int val)
{
    if (current == nullptr)
    {
        return nullptr;
    }

    if (current->left == nullptr && current->right == nullptr)
    {
        TreeNode *newNode = new TreeNode(val);
        if (current->val > val)
        {
            current->left = newNode;
        }
        else if (current->val < val)
        {
            current->right = newNode;
        }

        return current;
    }

    if (current->val > val)
    {
        if (current->left)
        {
            TreeNode *ans = insertIntoBST(current->left, val);
        }
        else
        {
            current->left = new TreeNode(val);
        }
    }

    else if (current->val < val)
    {
        if (current->right)
        {
            TreeNode *ans = insertIntoBST(current->right, val);
        }
        else
        {
            current->right = new TreeNode(val);
        }
    }

    return current;
}

TreeNode *insertion(TreeNode *current, int val)
{
    if (current == nullptr)
    {
        return new TreeNode(val);
    }
    if (val > current->val)
    {
        TreeNode *ans = insertion(current->right, val);
        current->right = ans;
    }
    else
    {
        TreeNode *ans = insertion(current->left, val);
        current->left = ans;
    }

    return current;
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

    printTree(insertIntoBST(root, 11));

    return 0;
}