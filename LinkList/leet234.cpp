// 234. Palindrome Linked List

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

ListNode *middleFind(ListNode *head)
{
    // find length
    int length = 0;
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
    return middleNode;
}

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *node = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}
bool isPalindrome(ListNode *head)
{

    bool isPalindrome = false;
    ListNode *head1 = head;
    ListNode *middle = middleFind(head);
    cout << "Middle Value is : " << middle->val << endl;

    ListNode *head2 = reverseList(middle);

    // head1 == head2

    while (true)
    {
        if (head1 == head2)
        {
            isPalindrome = true;
            break;
        }
        if (head1->val != head2->val)
        {
            break;
        }
        else
        {
            if (head1->next != NULL && head2->next != NULL)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            else
            {
                isPalindrome = true;
                break;
            }
        }
    }

    return isPalindrome;
}

int main()
{
    int arr[] = {1, 2, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);

    bool ans = isPalindrome(head);

    cout << ans << endl;

    return 0;
}