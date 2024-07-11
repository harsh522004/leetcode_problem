// Construct Binary Search Tree from Preorder Traversal

#include "../binarytree/binary_tree.h"
#include <vector>
#include <stack>
TreeNode *createTree(vector<int> &preOrder, int i, int k)
{

    cout << endl;
    cout << endl;
    cout << "i -> " << i << endl;
    cout << "k -> " << k << endl;

    if (i > k || i < 0)
    {
        cout << "return null" << endl;
        return nullptr;
    }
    // base cases
    if (i == k)
    {
        cout << "i == k" << "  return.... " << preOrder[i] << endl;
        return new TreeNode(preOrder[i]);
    }

    // current node
    TreeNode *currentNode = new TreeNode(preOrder[i]);

    cout << "current -> " << currentNode->val << endl;

    int j = i + 1;

    // left call
    while (j <= k && currentNode->val > preOrder[j])
    {
        j++;
    }

    cout << "j -> " << j << endl;

    if (preOrder[i + 1] < currentNode->val)
    {
        cout << "Call for left " << endl;
        currentNode->left = createTree(preOrder, i + 1, j - 1);
        if (currentNode->left != nullptr)
            cout << "Left -> " << currentNode->left->val << endl;
        else
        {
            cout << "Left is NULL" << endl;
        }
    }

    if (preOrder[j] > currentNode->val)
    {
        currentNode->right = createTree(preOrder, j, k);
        if (currentNode->right != nullptr)
            cout << "Right -> " << currentNode->right->val << endl;
        else
        {
            cout << "right is NULL" << endl;
        }
    }

    cout << "Returning current node : " << currentNode->val << endl;
    return currentNode;
}

int main()
{
    vector<int> preOrder = {4, 2};
    createTree(preOrder, 0, preOrder.size() - 1);

    return 0;
}