//

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

void middleFind2(ListNode *head)
{
    // find length
    int length = 1;
    ListNode *node = head;
    while (node->next != NULL)
    {
        length++;
        node = node->next;
    }
    int middlePos = length / 2;

    node = head;
    ListNode *middleNode = NULL;
    ListNode *prevOfMiddle = NULL;
    while (true)
    {

        if (middlePos == 0)
        {

            middleNode = node;
            cout << "Middle Node is : " << middleNode->val << endl;
            cout << "prev value is" << prevOfMiddle->val << endl;

            // we have middle and prev of middle at this point
            prevOfMiddle->next = middleNode->next;
            middleNode->next = NULL;
            break;
        }
        else if (middlePos == 1)
        {

            prevOfMiddle = node;
            cout << "prev value set" << prevOfMiddle->val << endl;
        }
        else
        {
            middlePos--;
            node = node->next;
        }
    }

    cout << head->next->val << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);

    middleFind2(head);

    return 0;
}