// Reverse Node in k group

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

int lengthLinkedList(ListNode *head)
{
    int count = 0;
    ListNode *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

ListNode *reverseGroup(ListNode *head)
{
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* newHead = reverseGroup(head->next);
    newHead->next = head;
    head->next = nullptr;
}

int main()
{

    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);

    ListNode *curr = head;
    ListNode *pre = nullptr;
    ListNode *forward = (curr != nullptr) ? curr->next : nullptr;

    while (curr != nullptr && curr->next != nullptr)
    {
        curr->next = pre;
        pre = curr;
        curr = forward;
        forward = (forward != nullptr) ? forward->next : nullptr;
    }

    curr->next = pre;
    printLinkedList(curr);

   

    return 0;
}
