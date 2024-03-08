// 110 balance Binary Tree

#include "binary_tree.h"
#include <vector>
#include <queue>
#include <cmath>

pair<int, bool> BT(TreeNode *node)
{
    // base case with 0 height and true ans
    if (node == nullptr)
    {
        return make_pair(0, true);
    }

    // left call
    pair<int, bool> leftpair = BT(node->left);

    // right call
    pair<int, bool> rightpair = BT(node->right);

    // cond 1 is abs difference bte two heights
    bool cond1 = ((abs(leftpair.first - rightpair.first)) <= 1);

    // cond 2 is true, if true comes from both side
    bool cond2 = ((leftpair.second) && (rightpair.second));

    // Action according to conds
    if (cond1 && cond2)
    {
        return make_pair(max(rightpair.first, leftpair.first) + 1, true);
    }
    else
    {
        return make_pair(max(rightpair.first, leftpair.first) + 1, false);
    }
}

bool isBalanced(TreeNode *root)
{
    pair<int, bool> ans = BT(root);
    return ans.second;
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

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    cout << isBalanced(root);

    return 0;
}