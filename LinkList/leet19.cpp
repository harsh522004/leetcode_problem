// 19. Remove Nth Node From End of List

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

void removeNthFromEnd(ListNode *head, int n)
{
    if (head->next == NULL && n != 0)
    {
        return;
    }
    ListNode *currentNode = head;
    ListNode *prevNode = head;
    while (true)
    {
        cout << "Current Node is : " << currentNode->val << endl;
        cout << "Prev Node is : " << prevNode->val << endl;
        int counter = 0;
        ListNode *node = currentNode;
        while (counter != n)
        {
            node = node->next;
            counter++;
        }
        if (node == nullptr)
        {
            // currentNode is our final ans
            cout << "current Node is our Ans" << endl;
            if (prevNode == currentNode)
            {
                head = currentNode->next;
                prevNode->next = nullptr;
                break;
            }
            prevNode->next = currentNode->next;
            currentNode->next = nullptr;
            break;
        }
        else
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    printLinkedList(head);
}
int main()
{
    int arr[] = {1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);

    removeNthFromEnd(head, 2);

    return 0;
}