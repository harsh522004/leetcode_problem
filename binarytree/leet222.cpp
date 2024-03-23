// 222. Count Complete Tree Nodes

#include "binary_tree.h"
#include <vector>
#include <queue>
#include <cmath>

int countNodes(TreeNode *root)
{
    bool isFirst = true;
    bool isLastSecond = false;
    int height = 1;
    int childs = 0;
    queue<TreeNode *> nodes;
    nodes.push(root);
    nodes.push(nullptr);
    while (!nodes.empty())
    {
        TreeNode *front = nodes.front();

        nodes.pop();

        if (front == nullptr && !nodes.empty())
        {
            height++;
            nodes.push(nullptr);
            isFirst = true;
        }
        else
        {
            if (isFirst)
            {
                if (front->left->left == nullptr)
                {
                    isLastSecond = true;
                }
                else
                {
                    isLastSecond = false;
                    isFirst = !(isFirst);
                }
            }
            if (isLastSecond)
            {
                while (!nodes.empty())
                {
                    if (front->left != nullptr)
                        childs++;
                    if (front->right != nullptr)
                        childs++;
                    front = nodes.front();
                    nodes.pop();
                }
            }
            else
            {
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
    }

    height = pow(2, height) - 1;

    return height + childs;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(8);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    cout << countNodes(root);

    return 0;
}