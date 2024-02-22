// 141 Linked List Cycle
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

bool hasCycle(ListNode *head)
{
    ListNode *noob = head;
    ListNode *pro = head;
    bool flag = false;
    while (pro != NULL || pro->next != NULL)
    {
        pro = pro->next->next;
        noob = noob->next;
        if (pro == noob)
        {
            flag = true;
            break;
        }
    }

    return flag;
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);
}