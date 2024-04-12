// delet from BST

#include "../binarytree/binary_tree.h"
#include <vector>
#include <stack>

// insertion
TreeNode *insertion(TreeNode *current, TreeNode *value)
{
    if (current == nullptr)
    {
        return value;
    }
    if (value->val > current->val)
    {
        TreeNode *ans = insertion(current->right, value);
        current->right = ans;
    }
    else
    {
        TreeNode *ans = insertion(current->left, value);
        current->left = ans;
    }

    return current;
}

// search node
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val == val)
    {
        TreeNode *leftTree = root->left;
        TreeNode *rightTree = root->right;
        root->left = nullptr;
        root->right = nullptr;
        delete (root);

        if (rightTree != nullptr)
        {
            TreeNode *newLeftTree = insertion(leftTree, rightTree);
            return newLeftTree;
        }
    }

    if (root->val > val)
    {
        TreeNode *left = searchBST(root->left, val);
        if (root->left)
            root->left = left;
    }
    else
    {
        TreeNode *right = searchBST(root->right, val);
        if (root->right)
            root->right = right;
    }

    return root;
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
    root->right->right = new TreeNode(16);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(26);
    root->right->right->left->left = new TreeNode(11);
    root->right->right->left->right = new TreeNode(15);

    root->right->right->right->left = new TreeNode(23);
    root->right->right->right->right = new TreeNode(29);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    printTree(searchBST(root, 16));

    return 0;
}