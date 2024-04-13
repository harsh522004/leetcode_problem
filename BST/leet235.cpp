//  Lowest Common Ancestor of a Binary Search Tree

#include "../binarytree/binary_tree.h"
#include <vector>
#include <stack>
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *u, TreeNode *v)
{
    int val = root->val;

    TreeNode *ans = nullptr;

    while (true)
    {
        val = root->val;

        bool case1 = (u->val > val && v->val > val); // move right
        bool case2 = (u->val < val && v->val < val); // move left
        bool case3 = (u->val == val);                // ans is u
        bool case4 = (v->val == val);                // ans is v
        bool case5 = (u->val < val && v->val > val); // current node is ans
        bool case6 = (v->val < val && u->val > val); // current node is ans

        if (case3)
        {

            ans = u;
            break;
        }
        else if (case4)
        {

            ans = v;
            break;
        }
        else if (case5 || case6)
        {

            ans = root;
            break;
        }
        else if (case1)
        {

            root = root->right;
        }
        else if (case2)
        {

            root = root->left;
        }
    }

    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(16);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(26);
    root->right->right->left->left = new TreeNode(11);
    root->right->right->left->right = new TreeNode(15);

    root->right->right->right->left = new TreeNode(23);
    root->right->right->right->right = new TreeNode(29);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    cout << lowestCommonAncestor(root, root->left->right, root->left->right->left)->val;

    return 0;
}