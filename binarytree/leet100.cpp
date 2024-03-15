#include "binary_tree.h"

// < Current Node, Parents Value >

bool function(pair<TreeNode *, int> firstTree, pair<TreeNode *, int> secondTree)
{

    // base case
    if (firstTree.first == nullptr && secondTree.first == nullptr)
    {
        // flag is alredy set
        return true;
    }

    if (firstTree.first == nullptr || secondTree.first == nullptr)
    {

        return false;
    }

    // conditions that should not right

    if (firstTree.second != secondTree.second || firstTree.first->val != secondTree.first->val)
    {

        return false;
    }

    // left from both tree
    bool left = function(make_pair(firstTree.first->left, firstTree.first->val), make_pair(secondTree.first->left, secondTree.first->val));

    // go Right from Both Tree
    bool right = function(make_pair(firstTree.first->right, firstTree.first->val), make_pair(secondTree.first->right, secondTree.first->val));

    return (left && right);
}
int main()
{
    // tree1
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // tree2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    bool flag = function(make_pair(root1, -1), make_pair(root2, -1));
    cout << flag;
    return 0;
}
