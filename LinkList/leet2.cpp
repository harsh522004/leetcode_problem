// add to Number

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

int listToNumber(ListNode *head)
{
    if (head == nullptr)
    {
        return 0;
    }
    int number1 = 0;
    ListNode *node = head;
    while (node != nullptr)
    {
        int val = node->val;
        number1 = (number1 * 10) + val;
        node = node->next;
    }

    return number1;
}

ListNode *numberToList(int number)
{
    if (number == 0)
    {
        return new ListNode(0);
    }
    int originalNumber = number;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    while (number != 0)
    {
        int digit = number % 10;

        ListNode *node = new ListNode(digit);
        tail->next = node;
        tail = tail->next;
        number = number / 10;
    }

    ListNode *ans = dummy->next;
    delete dummy;

    return ans;
}

void *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;

    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    ListNode *node1 = l1;
    ListNode *node2 = l2;

    while (!(node1 == nullptr && node2 == nullptr))
    {
        int digit1 = (node1 != nullptr) ? node1->val : 0;
        int digit2 = (node2 != nullptr) ? node2->val : 0;

        int sum = digit1 + digit2 + carry;

        ListNode *node = new ListNode(sum % 10);
        tail->next = node;
        tail = tail->next;
        carry = sum / 10;
        if (node1 != nullptr)
            node1 = node1->next;
        if (node2 != nullptr)
            node2 = node2->next;
    }

    if (carry != 0)
    {
        ListNode *node = new ListNode(carry);
        tail->next = node;
        tail = tail->next;
    }

    printLinkedList(dummy->next);
}
int main()
{
    int arr[] = {2, 4, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);

    int arr2[] = {5, 6, 4, 9};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    ListNode *head2 = createLinkedList(arr2, size2);

    addTwoNumbers(head, head2);

    return 0;
}