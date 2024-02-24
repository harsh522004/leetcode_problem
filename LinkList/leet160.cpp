// 160. Intersection of Two Linked Lists

#include <iostream>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createLinkedList(int arr[], int size)
{
    if (size == 0)
    {
        return nullptr; // Return null if the array is empty
    }

    ListNode *head = new ListNode(arr[0]); // Create the first node

    ListNode *current = head; // Pointer to the current node

    // Iterate through the array to create the rest of the linked list
    for (int i = 1; i < size; ++i)
    {
        current->next = new ListNode(arr[i]); // Create a new node
        current = current->next;              // Move the current pointer to the new node
    }

    return head; // Return the head of the linked list
}

void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    map<ListNode *, bool> visit;
    ListNode *interSectionNode = nullptr;
    ListNode *node = headA;
    while (node != nullptr)
    {
        visit[node] = true;
        node = node->next;
    }

    ListNode *secondNode = headB;
    while (secondNode != nullptr)
    {
        auto it = visit.find(secondNode);
        if (it != visit.end())
        {
            // it alredy visited
            interSectionNode = secondNode;
            break;
        }
        secondNode = secondNode->next;
    }

    if (interSectionNode == nullptr)
    {
        return nullptr;
    }

    return interSectionNode;
}
int main()
{
    int arr[] = {1, 2, 3, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode *head1 = createLinkedList(arr, size);

    int arr2[] = {4, 5, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode *head2 = createLinkedList(arr2, size2);

    head2->next->next->next = head1->next->next->next;

    ListNode *tamp = getIntersectionNode(head1, head2);

    cout << tamp->val << endl;

    return 0;
}