// 230. Kth Smallest Element in a BST

#include "../binarytree/binary_tree.h"
#include <vector>
#include <stack>

void inorder(TreeNode *head, int &count, int k, int &element)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->left)
        inorder(head->left, count, k, element);

    count++;
    if (count == k)
    {
        element = head->val;
        return;
    }
    else
    {
        if (head->right && element == -1)
            inorder(head->right, count, k, element);
    }

    return;
}

int kthSmallest(TreeNode *root, int k)
{
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(6);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    int element = -1;
    int count = 0;
    inorder(root, count, 2, element);
    cout << element << endl;

    return 0;
}