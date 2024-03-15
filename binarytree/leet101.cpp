#include "binary_tree.h"

// < position at parents , current Node>

// left = 0
// right = 1

bool isSymmetric(pair<bool, TreeNode *> lefttree, pair<bool, TreeNode *> righttree)
{
    TreeNode *leftTreeNode = lefttree.second;
    TreeNode *rightTreeNode = righttree.second;

    if ((leftTreeNode == nullptr && rightTreeNode != nullptr) || (leftTreeNode != nullptr && rightTreeNode == nullptr))
    {

        return false;
    }

    if (leftTreeNode == nullptr && rightTreeNode == nullptr)
    {
        return true;
    }
    bool leftPos = lefttree.first;
    bool rightPos = righttree.first;

    int leftVal = lefttree.second->val;
    int rightVal = righttree.second->val;

    // pos must be different
    if (leftPos == rightPos || leftVal != rightVal)
    {

        return false;
    }

    bool leftside = isSymmetric(make_pair(0, lefttree.second->left), make_pair(1, righttree.second->right));
    bool rightside = isSymmetric(make_pair(1, lefttree.second->right), make_pair(0, righttree.second->left));

    return leftside && rightside;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    cout << isSymmetric(make_pair(0, root->left), make_pair(1, root->right));

    return 0;
}
