// 103. Binary Tree Zigzag Level Order Traversal
#include "binary_tree.h"
#include <deque>

void zigzag(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    vector<vector<int>> result;

    // < Node , level >
    deque<pair<TreeNode *, int>> nodes;
    nodes.push_back(make_pair(root, 0));
    int oldLevel = 0;
    bool flag = 1;
    vector<int> ans = {};

    while (!nodes.empty())
    {
        if (flag == 0 && nodes.back().second != oldLevel)
        {
            flag = !flag;
            oldLevel = nodes.front().second;
            result.push_back(ans);
            ans = {};
            // we shold update old Level here
        }
        if (flag == 1 && nodes.front().second != oldLevel)
        {
            flag = !flag;
            oldLevel = nodes.front().second;
            result.push_back(ans);
            ans = {};
            // we shold update old Level here
        }

        if (flag)
        {
            pair<TreeNode *, int> frontElement = nodes.front();
            nodes.pop_front();
            ans.push_back(frontElement.first->val);
            if (frontElement.first->left != nullptr)
            {
                nodes.push_back(make_pair(frontElement.first->left, frontElement.second + 1));
            }
            if (frontElement.first->right != nullptr)
            {
                nodes.push_back(make_pair(frontElement.first->right, frontElement.second + 1));
            }
        }
        else
        {
            pair<TreeNode *, int> backElement = nodes.back();
            nodes.pop_back();
            ans.push_back(backElement.first->val);
            if (backElement.first->right != nullptr)
            {
                nodes.push_front(make_pair(backElement.first->right, backElement.second + 1));
            }
            if (backElement.first->left != nullptr)
            {
                nodes.push_front(make_pair(backElement.first->left, backElement.second + 1));
            }
        }
    }

    if (!ans.empty())
    {
        result.push_back(ans);
    }

    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << "  ";
        }
        cout << endl;
    }
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
    zigzag(root);
    return 0;
}