#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <vector>
#include <queue>
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

void printBFS(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
        cout << endl; // Print a new line after each level
    }
}

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