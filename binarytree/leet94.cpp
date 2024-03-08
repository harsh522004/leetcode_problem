// in order
#include "binary_tree.h"
#include <vector>
#include <stack>
void In(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    In(root->left, ans);
    ans.push_back(root->val);
    In(root->right, ans);
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

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    vector<int> ans;
    In(root, ans);
    printVector(ans);
    return 0;
}