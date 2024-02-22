// 876 Middle of the Linked List

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

void middleFind(ListNode *head)
{
    // find length
    int length = 1;
    ListNode *node = head;
    while (node->next != NULL)
    {
        length++;
        node = node->next;
    }

    cout << "length is" << length << endl;
    int middlePos = length / 2;
    cout << "middle position is" << middlePos << endl;
    int counter = 1;
    node = head;
    ListNode *middleNode = head;
    while (true)
    {
        if (counter == middlePos + 1)
        {
            middleNode = node;
            break;
        }
        else
        {
            counter++;
            node = node->next;
        }
    }

    cout << middleNode->val << endl;
}

// without counter

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
    while (true)
    {
        if (middlePos == 0)
        {
            middleNode = node;
            break;
        }
        else
        {
            middlePos--;
            node = node->next;
        }
    }

    cout << middleNode->val << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);

    middleFind(head);

    return 0;
}