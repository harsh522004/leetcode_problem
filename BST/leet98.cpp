// Validate Binary Search Tree

#include "../binarytree/binary_tree.h"
#include <vector>
#include <stack>

void inorder(TreeNode *head, vector<int> &ans)
{
    if (head == nullptr)
    {
        return;
    }

    inorder(head->left, ans);
    ans.push_back(head->val);
    inorder(head->right, ans);
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

    vector<int> ans;
    inorder(root, ans);
    bool flag = true;

    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            flag = false;
        }
    }

    cout << flag << endl;

    return 0;
}