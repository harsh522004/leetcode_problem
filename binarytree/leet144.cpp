// pre order

#include "binary_tree.h"
#include <vector>
#include <stack>

void preorderTraversal(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    ans.push_back(root->val);
    preorderTraversal(root->left, ans);
    preorderTraversal(root->right, ans);
}

vector<int> preorderTraversal2(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<int> current;
    current.push_back(root->val);

    vector<int> left = preorderTraversal2(root->left);
    vector<int> right = preorderTraversal2(root->right);

    left.insert(left.end(), right.begin(), right.end());
    current.insert(current.end(), left.begin(), left.end());

    return current;
}

vector<int> preorderTraversal3(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }

    vector<int> result;
    stack<TreeNode *> ds;
    ds.push(root);

    while (!ds.empty())
    {
        TreeNode *front = ds.top();
        ds.pop();

        result.push_back(front->val);

        // right call
        if (front->right != nullptr)
        {
            ds.push(front->right);
        }

        // left call
        if (front->left != nullptr)
        {
            ds.push(front->left);
        }
    }

    return result;
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
    // vector<int> ans;
    // preorderTraversal(root, ans);
    // printVector(ans);

    vector<int> ans = preorderTraversal2(root);
    printVector(ans);

    return 0;
}