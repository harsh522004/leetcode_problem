// Serialize and Deserialize Binary Tree

#include "binary_tree.h"
#include <vector>
#include <stack>
#include <queue>

string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "";
    }
    queue<TreeNode *> nodes;
    nodes.push(root);
    string data;
    while (!nodes.empty())
    {
        TreeNode *front = nodes.front();
        nodes.pop();

        if (front != nullptr)
        {
            data += to_string(front->val);
            nodes.push(front->left);
            nodes.push(front->right);
        }
        else
        {
            data = data + '#';
        }
    }

    return data;
}

TreeNode *deserialize(string data)
{
    if (data.empty())
    {
        return nullptr;
    }

    queue<TreeNode *> nodes;

    TreeNode *root = new TreeNode(data[0] - '0');
    nodes.push(root);
    int index = 1;
    while (!nodes.empty())
    {

        TreeNode *frontNode = nodes.front();

        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        char leftValue = data[index];

        if (leftValue != '#')
        {
            left = new TreeNode(leftValue - '0');
            nodes.push(left);
        }
        index++;

        char rightValue = data[index];
        if (rightValue != '#')
        {
            right = new TreeNode(rightValue - '0');
            nodes.push(right);
        }
        index++;

        frontNode->left = left;
        frontNode->right = right;

        nodes.pop();
    }

    return root;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string ans = serialize(root);
    cout << ans << endl;

    TreeNode *root2 = deserialize(ans);
    cout << "Binary Tree: ";
    printTree(root2);
    cout << endl;

    return 0;
}