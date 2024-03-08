#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    printTree(root->left);

    cout << root->val << " ";

    printTree(root->right);
}

void printVector(vector<int> ans)
{
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}
#endif