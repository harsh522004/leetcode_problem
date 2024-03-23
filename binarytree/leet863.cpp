// 863. All Nodes Distance K in Binary Tree

#include "binary_tree.h"
#include <unordered_map>
#include <stack>
#include <queue>

void printNodesInStack(stack<TreeNode *> s)
{
    cout << "Nodes in the stack:" << endl;
    while (!s.empty())
    {
        cout << s.top()->val << " ";
        s.pop();
    }
    cout << endl;
}

unordered_map<TreeNode *, TreeNode *> createMaps(TreeNode *root)
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

bool isElementPresent(stack<TreeNode *> s, TreeNode *node)
{
    while (!s.empty())
    {
        if (s.top() == node)
        {
            return true; // Node found in stack
        }
        s.pop(); // Pop the top element and continue searching
    }
    return false; // Node not found in stack
}

// < current Node, distance >
void function(pair<TreeNode *, int> targetPair, stack<TreeNode *> &currentNodesStack,

              unordered_map<TreeNode *, TreeNode *> &childToParent, vector<int> &ans)
{

    TreeNode *currentNode = targetPair.first;
    int distance = targetPair.second;

    // cout << "Current Node is : " << currentNode->val << endl;
    // cout << "Distance is : " << distance << endl;
    // cout << endl;

    // cout << "Current Stack Is : " << endl;

    // cout << endl;

    bool isAlredyProgress = isElementPresent(currentNodesStack, currentNode);

    // cout << "Is Alredy in Stack : " << isAlredyProgress << endl;

    if (isAlredyProgress)
    {
        // cout << "Alredy in Stack" << endl;
        return;
    }

    if (distance == 0)
    {
        // cout << "Distance is Zero " << endl;
        ans.push_back(currentNode->val);
        // cout << "Ans is : ";
        // for (auto x : ans)
        //{
        //     cout << x << " ";
        // }
        // cout << endl;

        return;
    }

    // cout << "Element Push" << endl;
    //  add current node in queue
    currentNodesStack.push(currentNode);

    // child call
    if (currentNode->left != nullptr && !isElementPresent(currentNodesStack, currentNode->left))
    {
        // cout << "Call for Left Child :" << currentNode->left->val << " "
        //      << "Distance is : " << distance - 1 << endl;
        function(make_pair(currentNode->left, distance - 1), currentNodesStack, childToParent, ans);
    }

    if (currentNode->right != nullptr && !isElementPresent(currentNodesStack, currentNode->right))
    {
        // cout << "Call for right Child :" << currentNode->right->val << " "
        //      << "Distance is : " << distance - 1 << endl;
        function(make_pair(currentNode->right, distance - 1), currentNodesStack, childToParent, ans);
    }

    // parents call
    if (childToParent.find(currentNode) != childToParent.end() && !isElementPresent(currentNodesStack, childToParent[currentNode]))
    {
        // cout << "Call for Parents :" << childToParent[currentNode]->val << " "
        //     << "Distance is : " << distance - 1 << endl;
        function(make_pair(childToParent[currentNode], distance - 1), currentNodesStack, childToParent, ans);
    }

       //  here use stack
    currentNodesStack.pop();
}

void distanceK(TreeNode *root, TreeNode *target, int k)
{

    // crreated hash map
    unordered_map<TreeNode *, TreeNode *> childToParent = createMaps(root);

    cout << "Child-Parent Map:" << endl;
    for (auto it : childToParent)
    {
        cout << it.first->val << " -> " << it.second->val << endl;
    }

    stack<TreeNode *> s;
    vector<int> ans;
    function(make_pair(target, k), s, childToParent, ans);

    for (auto x : ans)
    {
        cout << x << " ";
    }
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(11);
    root->right->left->right = new TreeNode(12);
    root->right->right->left = new TreeNode(10);
    root->right->right->right = new TreeNode(4);
    distanceK(root, root->right->left, 3);

    return 0;
}