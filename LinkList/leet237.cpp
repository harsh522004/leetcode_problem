// 237. Delete Node in a Linked List

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
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteNode(ListNode *node, ListNode *head)
{

    while (true)
    {
        int val = node->next->val;
        node->val = val;
        if (node->next->next != NULL)
        {
            node = node->next;
        }
        else
        {
            node->next = NULL;
            break;
        }
    }

    printLinkedList(head);

    // Change the value

    // end check
}
int main()
{

    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);
    deleteNode(head->next, head);
    return 0;
}