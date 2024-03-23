// 105. Construct Binary Tree from Preorder and Inorder Traversal

#include "binary_tree.h"
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>

int findIndex(vector<int> &nodes, int value)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i] == value)
        {
            return i;
        }
    }
}

// ap 1
int findFirst(vector<int> &preOrder, vector<int> findFrom)
{
    for (int i = 0; i < preOrder.size(); i++)
    {
        int element = preOrder[i];
        auto it = find(findFrom.begin(), findFrom.end(), element);
        if (it != findFrom.end())
        {
            return element;
            // std::cout << "Element " << target << " found at index " << (it - vec.begin()) << std::endl;
        }
    }
}

TreeNode *Tampfunction(vector<int> &nodes, int value, vector<int> &preorder)
{
    if (nodes.size() == 0)
    {
        return nullptr;
    }
    TreeNode *tamp = new TreeNode(value);

    if (nodes.size() == 1)
    {

        return tamp;
    }

    vector<int> left;
    vector<int> right;

    bool isLeft = true;
    // create left vector
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i] == value)
        {
            isLeft = false;
        }
        else
        {
            if (isLeft)
            {
                left.push_back(nodes[i]);
            }
            else
            {
                right.push_back(nodes[i]);
            }
        }
    }

    int a = left.size() != 0 ? findFirst(preorder, left) : 0;
    int b = right.size() != 0 ? findFirst(preorder, right) : 0;

    tamp->left = Tampfunction(left, a, preorder);

    tamp->right = Tampfunction(right, b, preorder);

    return tamp;
}

// ap 2
TreeNode *tree(vector<int> preorder, vector<int> inorder, int &preindex, int inorderstart, int inorderend)
{
    if (preindex >= preorder.size() || inorderstart > inorderend)
    {
        return NULL;
    }
    int element = preorder[preindex++];
    TreeNode *root = new TreeNode(element);
    int pos = findposition(inorder, element);

    root->left = tree(preorder, inorder, preindex, inorderstart, pos - 1);
    root->right = tree(preorder, inorder, preindex, pos + 1, inorderend);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preindex = 0;
    int inorderstart = 0;
    int inorderend = inorder.size() - 1;
    return tree(preorder, inorder, preindex, inorderstart, inorderend);
}
int main()
{

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    // root->left->left->right = new TreeNode(8);

    vector<int> preorder = {1, 2, 8, 3, 9, 6, 4};
    vector<int> inorder = {8, 2, 1, 9, 3, 4, 6};

    // TreeNode *root = Tampfunction(inorder, 1, preorder);
    // cout << root->val << endl;

    TreeNode *root = buildTree(inorder, preorder, 0, 0, inorder.size() - 1);

    printTree(root);

    return 0;
}