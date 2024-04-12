// 236. Lowest Common Ancestor of a Binary Tree

#include "binary_tree.h"
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

unordered_map<TreeNode *, TreeNode *> createChildParentMap(TreeNode *root)
{
    unordered_map<TreeNode *, TreeNode *> childParentMap;

    if (root == nullptr)
    {
        return childParentMap;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *parent = q.front();
        q.pop();

        if (parent->left != nullptr)
        {
            q.push(parent->left);
            childParentMap[parent->left] = parent;
        }
        if (parent->right != nullptr)
        {
            q.push(parent->right);
            childParentMap[parent->right] = parent;
        }
    }

    return childParentMap;
}

// Function to get the parent of a node from the childParentMap
TreeNode *getParent(unordered_map<TreeNode *, TreeNode *> &childParentMap, TreeNode *node)
{
    if (childParentMap.find(node) != childParentMap.end())
    {
        return childParentMap[node];
    }
    return nullptr;
}

void printNode(TreeNode *node)
{
    if (node == nullptr)
    {
        cout << "node is null" << endl;
        return;
    }
    cout << "Node is : " << node->val << endl;
    return;
}

void printVector1(vector<TreeNode *> ans)
{
    for (auto x : ans)
    {
        cout << x->val << " ";
    }
    cout << endl;
}

void parentsVector(unordered_map<TreeNode *, TreeNode *> &childParentMap, TreeNode *root, TreeNode *start, vector<TreeNode *> &ans)
{
    if (start == root)
    {
        ans.push_back(start);
        return;
    }
    TreeNode *parent = getParent(childParentMap, start);
    ans.push_back(start);
    parentsVector(childParentMap, root, parent, ans);
}

TreeNode *longestCommon(TreeNode *p, TreeNode *q, TreeNode *root)
{
    vector<TreeNode *> parentsOfP;
    vector<TreeNode *> parentsOfQ;

    unordered_map<TreeNode *, TreeNode *> childParentMap = createChildParentMap(root);

    parentsVector(childParentMap, root, p, parentsOfP);
    parentsVector(childParentMap, root, q, parentsOfQ);

    unordered_set<TreeNode *> set;

    // Insert elements of vec1 into the set
    for (auto num : parentsOfP)
    {
        set.insert(num);
    }

    // Iterate through vec2 to find the first common element
    for (auto num : parentsOfQ)
    {
        if (set.find(num) != set.end())
        {
            return num; // First common element found
        }
    }

    return root;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    cout << longestCommon(root->left->left, root->left->right->right, root)->val << endl;

    return 0;
}