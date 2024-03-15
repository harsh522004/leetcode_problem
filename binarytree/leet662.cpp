// max width
#include "binary_tree.h"
#include <queue>
/*
// bool hasNonNullNodes(const queue<TreeNode *> &q)
// {

//     queue<TreeNode *> qCopy = q;

//     while (!qCopy.empty())
//     {

//         TreeNode *node = qCopy.front();
//         qCopy.pop();

//         if (node != nullptr)
//         {
//             return true;
//         }
//     }

//     return false;
// }

// int maxWidthfromVector(vector<vector<TreeNode *>> &result)
// {

//     int maxWidth = 0;

//     for (auto array : result)
//     {

//         int currentWidth = 0;
//         int leftNonNullindex = 0;
//         int rightNonNullindex = 0;
//         for (int i = 0; i < array.size(); i++)
//         {
//             if (array[i] != nullptr)
//             {
//                 leftNonNullindex = i;
//                 break;
//             }
//         }
//         for (int j = array.size() - 1; j >= 0; j--)
//         {
//             if (array[j] != nullptr)
//             {
//                 rightNonNullindex = j;
//                 break;
//             }
//         }

//         if (leftNonNullindex == rightNonNullindex)
//         {
//             currentWidth = 1;
//         }
//         else
//         {
//             currentWidth = (rightNonNullindex - leftNonNullindex) + 1;
//         }

//         maxWidth = max(currentWidth, maxWidth);
//     }

//     return maxWidth;
// }
// void maxWidth(TreeNode *root)
// {
//     queue<TreeNode *> nodes;
//     nodes.push(root);
//     int oldLevel = 1;
//     vector<vector<TreeNode *>> result;
//     vector<TreeNode *> ans;
//     while (hasNonNullNodes(nodes) && !nodes.empty())
//     {
//         if (ans.size() == oldLevel)
//         {
//             result.push_back(ans);
//             ans = {};
//             oldLevel = oldLevel * 2;
//         }
//         TreeNode *frontNode = nodes.front();
//         nodes.pop();
//         ans.push_back(frontNode);

//         // if front is null then add two null child
//         if (frontNode == nullptr)
//         {
//             TreeNode *child1 = nullptr;
//             TreeNode *child2 = nullptr;
//             nodes.push(child1);
//             nodes.push(child2);
//         }
//         else
//         {
//             if (frontNode->left != nullptr)
//             {
//                 nodes.push(frontNode->left);
//             }
//             else
//             {
//                 TreeNode *child = nullptr;
//                 nodes.push(child);
//             }

//             if (frontNode->right != nullptr)
//             {
//                 nodes.push(frontNode->right);
//             }
//             else
//             {
//                 TreeNode *child3 = nullptr;
//                 nodes.push(child3);
//             }
//         }
//     }

//     result.push_back(ans);

//         cout << maxWidthfromVector(result);
// }
*/

void maxWidth(TreeNode *root)
{
    // <node and index>
    queue<pair<TreeNode *, int>> que;
    que.push(make_pair(root, 0));
    que.push(make_pair(nullptr, 0));
    int maxwidth = 0;
    int currentIndex = 0;
    int oldIndex = 0;
    bool isFirst = true;

    while (!que.empty())
    {

        pair<TreeNode *, int> frontPair = que.front();
        que.pop();

               if (frontPair.first == nullptr)
        {
            int width = currentIndex - oldIndex;
            maxwidth = max(maxwidth, width + 1);
            if (!que.empty())
                que.push(make_pair(nullptr, 0));
            isFirst = true;
        }
        else
        {
            // update Index according
            if (isFirst)
            {
                oldIndex = frontPair.second;

                isFirst = false;
            }

            currentIndex = frontPair.second;

            // add child with new Index
            if (frontPair.second == 0)
            {
                if (frontPair.first->left != nullptr)
                {
                    que.push(make_pair(frontPair.first->left, (2 * (frontPair.second) + 1)));
                }
                if (frontPair.first->right != nullptr)
                {
                    que.push(make_pair(frontPair.first->right, (2 * (frontPair.second) + 2)));
                }
            }
            else
            {
                if (frontPair.first->left != nullptr)
                {
                    que.push(make_pair(frontPair.first->left, (2 * (frontPair.second - 1) + 1)));
                }
                if (frontPair.first->right != nullptr)
                {
                    que.push(make_pair(frontPair.first->right, (2 * (frontPair.second - 1) + 2)));
                }
            }
        }
    }

    cout << "Max width is : " << maxwidth;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(4);
    // root->right->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(6);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(6);
    root->left->left->left->left = new TreeNode(7);
    root->left->left->left->right = new TreeNode(8);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(9);

    // TreeNode *root = new TreeNode(1);
    // root->right = new TreeNode(2);
    // root->right->right = new TreeNode(3);
    // root->right->right->right = new TreeNode(4);
    // root->right->right->right->right = new TreeNode(5);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(3);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(5);
    // root->left->left->left = new TreeNode(6);
    // root->right->right = new TreeNode(9);
    // root->right->right->left = new TreeNode(7);

    cout << "Binary Tree: ";
    printTree(root);
    cout << endl;

    maxWidth(root);

    return 0;
}