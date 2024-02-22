// 328. Odd Even Linked List

#include <iostream>
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

void oddEvenList(ListNode *head)
{
    ListNode *joinHead = head->next;

    cout << "Join Head is : " << joinHead->val << endl;

    ListNode *oddNode = head;
    ListNode *evenNode = head->next;

    while (true)
    {

        if (oddNode->next == NULL || evenNode->next == NULL)
        {
            evenNode->next = NULL;
            oddNode->next = joinHead;
            break;
        }

        if (oddNode->next->next != NULL)
        {
            oddNode->next = oddNode->next->next;
            oddNode = oddNode->next;
        }

        if (evenNode->next->next != NULL)
        {
            evenNode->next = evenNode->next->next;
            evenNode = evenNode->next;
        }
    }

    printLinkedList(head);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);

    oddEvenList(head);

    return 0;
}