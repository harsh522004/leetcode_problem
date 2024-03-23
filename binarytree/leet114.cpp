// 114. Flatten Binary Tree to Linked List

#include "binary_tree.h"
#include <vector>
#include <stack>

// < first , last >
pair<TreeNode *, TreeNode *> funcion(TreeNode *root)
{

    // base case
    if (root == nullptr)
    {
        return make_pair(nullptr, nullptr);
    }
    if (root->right == nullptr && root->left == nullptr)
    {
        return make_pair(root, root);
    }

    // recursive call
    pair<TreeNode *, TreeNode *> leftPair = funcion(root->left);
    pair<TreeNode *, TreeNode *> rightPair = funcion(root->right);

    root->left = nullptr;
    // nomral cases
    if (leftPair.first == nullptr && rightPair.first != nullptr)
    {

        root->right = rightPair.first;
        return make_pair(root, rightPair.second);
    }
    if (leftPair.first != nullptr && rightPair.first == nullptr)
    {

        root->right = leftPair.first;
        return make_pair(root, leftPair.second);
    }
    if (leftPair.first != nullptr && rightPair.first != nullptr)
    {

        root->right = leftPair.first;
        leftPair.second->right = rightPair.first;
        return make_pair(root, rightPair.second);
    }
}
void flatten(TreeNode *root)
{
    pair<TreeNode *, TreeNode *> ans = funcion(root);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(6);

    cout << "Binary Tree: ";
    printBFS(root);
    cout << endl;

    flatten(root);

    cout << "Binary Tree After Function call: ";
    printBFS(root);
    cout << endl;

    return 0;
}