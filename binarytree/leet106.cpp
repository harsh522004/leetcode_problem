// 106. Construct Binary Tree from Inorder and Postorder Traversal
#include "binary_tree.h"
#include <vector>
#include <stack>
#include <algorithm>
vector<int> createNewPost(vector<int> &Newinorder, vector<int> &oldPost)
{
    vector<int> newPostOrder = {};
    int index = 0;
    while (newPostOrder.size() != Newinorder.size())
    {
        int element = oldPost[index];

        if (find(Newinorder.begin(), Newinorder.end(), element) != Newinorder.end())
        {
            newPostOrder.push_back(element);
        }

        index++;
    }

    return newPostOrder;
}

vector<vector<int>> createNewIn(vector<int> &oldInorder, int &rootElement)
{
    vector<int> ans;
    vector<int> ans1;
    vector<vector<int>> result;
    int index = 0;
    while (oldInorder[index] != rootElement)
    {
        ans.push_back(oldInorder[index]);
        index++;
    }

    index++;

    while (index != oldInorder.size())
    {
        ans1.push_back(oldInorder[index]);
        index++;
    }

    result.push_back(ans);
    result.push_back(ans1);
    return result;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() == 0)
    {
        return nullptr;
    }

    if (inorder.size() == 1 && postorder.size() == 1)
    {
        return new TreeNode(postorder[0]);
    }

    // pick root

    TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);

    // create new Inorder
    vector<vector<int>> result = createNewIn(inorder, root->val);
    vector<int> newInorderLeft = result[0];
    vector<int> newInorderRight = result[1];

    // create new postorder
    vector<int> newPostLeft = createNewPost(newInorderLeft, postorder);
    vector<int> newPostRight = createNewPost(newInorderRight, postorder);

    // left call
    root->left = buildTree(result[0], newPostLeft);

    // right call
    root->right = buildTree(result[1], newPostRight);

    return root;
}

TreeNode *indexingTree(vector<int> inorder, vector<int> postorder, int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd)
    {
        return nullptr;
    }

    // root
    TreeNode *root = new TreeNode(postorder[postEnd]);

    // find index
    int index = inStart;
    while (inorder[index] != root->val)
    {
        index++;
    }

    root->left = indexingTree(inorder, postorder, inStart, index - 1, postStart, postStart + (index - inStart) - 1);
    root->right = indexingTree(inorder, postorder, index + 1, inEnd, postStart + (index - inStart), postEnd - 1);

    return root;
}

int main()
{

    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    TreeNode *root = indexingTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    return 0;
}