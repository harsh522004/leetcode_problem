// 987. Vertical Order Traversal of a Binary Tree

#include "binary_tree.h"
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

bool customeCompare(pair<int, int> &a, pair<int, int> &b)
{

    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

void createMap(map<int, vector<pair<int, int>>> &mapping, TreeNode *root, int row, int col)
{
    if (root == nullptr)
    {
        return;
    }

    createMap(mapping, root->left, row + 1, col - 1);

    if (mapping.find(col) != mapping.end())
    {
        vector<pair<int, int>> tamp = mapping[col];
        tamp.push_back(make_pair(root->val, row));
        mapping[col] = tamp;
    }
    else
    {
        mapping[col] = {make_pair(root->val, row)};
    }

    createMap(mapping, root->right, row + 1, col + 1);
}

vector<vector<int>> verticalTraversal(TreeNode *root, map<int, vector<pair<int, int>>> &mapping)
{
    vector<vector<int>> result;
    for (auto &i : mapping)
    {
        vector<int> ans;
        vector<pair<int, int>> tamp = i.second;
        if (tamp.size() > 1)
        {
            sort(tamp.begin(), tamp.end(), customeCompare);
            for (auto j : tamp)
            {
                ans.push_back(j.first);
            }
        }
        else if (tamp.size() == 1)
        {
            ans.push_back(tamp[0].first);
        }

        result.push_back(ans);
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    map<int, vector<pair<int, int>>> mapping;

    createMap(mapping, root, 0, 0);

    for (auto i : mapping)
    {
        cout << "Column is : " << i.first << "---> ";
        for (auto j : i.second)
        {
            cout << "[" << j.first << "," << j.second << "]" << "  ";
        }
        cout << endl;
    }

    vector<vector<int>> ans = verticalTraversal(root, mapping);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}