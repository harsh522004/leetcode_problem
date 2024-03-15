// 199. Binary Tree Right Side View
#include "binary_tree.h"
#include <queue>
void rightSideView(TreeNode *root)
{
    vector<int> ans;
    ans.push_back(root->val);
    queue<TreeNode *> nodes;
    nodes.push(root);
    // TreeNode *tamp = nullptr;
    nodes.push(nullptr);

    while (!nodes.empty())
    {

        if (nodes.front() == nullptr)
        {
            // add another null to recognize level
            nodes.push(nullptr);

            // pop current null
            nodes.pop();

            if (nodes.front() == nullptr)
            {
                break;
            }

            // get right element
            int value = nodes.front()->val;

            // add into answer
            ans.push_back(value);
        }

        if (nodes.front()->right != nullptr)
        {
            nodes.push(nodes.front()->right);
        }
        if (nodes.front()->left != nullptr)
        {
            nodes.push(nodes.front()->left);
        }
        nodes.pop();
    }

    for (auto &x : ans)
    {
        cout << x << " ";
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    rightSideView(root);

    return 0;
}