// post
#include "binary_tree.h"
#include <vector>
#include <stack>
vector<int> postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<int> current;
    current.push_back(root->val);

    vector<int> left = postorderTraversal(root->left);
    vector<int> right = postorderTraversal(root->right);

    left.insert(left.end(), right.begin(), right.end());
    left.insert(left.end(), current.begin(), current.end());

    return left;
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

    vector<int> ans = postorderTraversal(root);
    printVector(ans);

    return 0;
}