// Sorting List
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
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < size; ++i)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
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

ListNode *middleFind2(ListNode *head)
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

    return middleNode;
}

ListNode *merge(ListNode *left, ListNode *right)
{
    cout << "Merge Called" << endl;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    while (left != nullptr && right != nullptr)
    {
        if (left->val <= right->val)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = (left != nullptr) ? left : right;

    ListNode *sortedList = dummy->next;
    delete dummy; // Free dummy node memory

    return sortedList;
}
ListNode *mergeSort(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *middle = middleFind2(head);
    ListNode *nextToMiddle = middle->next;

    middle->next = nullptr;

    ListNode *leftList = mergeSort(head);
    ListNode *rightList = mergeSort(nextToMiddle);

    return merge(leftList, rightList);
}

int main()
{

    int arr[] = {6, 7, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);

    cout << "Original list: ";
    printLinkedList(head);

    ListNode *sortedList = mergeSort(head);

    cout << "Sorted list: ";
    printLinkedList(sortedList);

    return 0;
}
