// BFS
#include "binary_tree.h"
#include <vector>
#include <queue>

vector<vector<int>> BFS(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode *> nodes;
    nodes.push(root);
    TreeNode *tamp = nullptr;
    nodes.push(tamp);
    vector<int> ans;

    while (!nodes.empty())
    {
        TreeNode *front = nodes.front();
        nodes.pop();

        if (front == nullptr)
        {
            result.push_back(ans);
            ans = {};
            if (!nodes.empty())
            {
                TreeNode *tamp = nullptr;
                nodes.push(tamp);
            }
        }
        else
        {
            ans.push_back(front->val);

            if (front->left != nullptr)
            {
                nodes.push(front->left);
            }
            if (front->right != nullptr)
            {
                nodes.push(front->right);
            }
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

    vector<vector<int>> ans = BFS(root);
    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}