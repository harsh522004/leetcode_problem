// 138. Copy List with Random Pointer

#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
#include <list>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *generateRandomLinkedList(const vector<pair<int, int>> &values)
{
    if (values.empty())
    {
        return nullptr;
    }

    unordered_map<int, Node *> nodeMap; // Map to store mapping from index to node

    // Create nodes with values
    vector<Node *> nodes;
    for (const auto &value : values)
    {
        Node *node = new Node(value.first);
        nodes.push_back(node);
        nodeMap[nodes.size() - 1] = node; // Store mapping from index to node
    }

    // Link nodes
    for (size_t i = 0; i < nodes.size() - 1; ++i)
    {
        nodes[i]->next = nodes[i + 1];
    }

    // Assign random pointers based on indices
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (values[i].second != -1)
        {
            nodes[i]->random = nodeMap[values[i].second];
        }
    }

    return nodes[0]; // Return head of the linked list
}

void printRandomLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << "[" << current->val << ", ";
        if (current->random != nullptr)
        {
            cout << current->random->val;
        }
        else
        {
            cout << "null";
        }
        cout << "] -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

void printMap(unordered_multimap<int, list<Node *>> &main)
{
    for (const auto &pair : main)
    {
        std::cout << "Value: " << pair.first << ", Next: ";
        if (pair.second.front() != nullptr)
        {
            std::cout << pair.second.front()->val << ", ";
        }
        else
        {
            std::cout << "null, ";
        }
        std::cout << "Random: ";
        if (pair.second.back() != nullptr)
        {
            std::cout << pair.second.back()->val << std::endl;
        }
        else
        {
            std::cout << "null" << std::endl;
        }
    }
}
void deepCopy(Node *head)
{
    unordered_multimap<int, list<Node *>> main;

    Node *tamp = head;

    // create Map with next and Random
    while (tamp != nullptr)
    {
        int value = tamp->val;

        Node *tampNext = tamp->next;
        Node *tampRandom = tamp->random;

        // cout << "Value : " << value << "  " <<  "Next : " << tampNext->val << "  " << "Random : " << tampRandom->val << endl;

        list<Node *> tampList;

        if (tampNext != nullptr)
            tampList.push_back(tampNext);
        else
            tampList.push_back(nullptr);
        if (tampRandom != nullptr)
            tampList.push_back(tampRandom);
        else
            tampList.push_back(nullptr);

        main.insert({value, tampList});
        tamp = tamp->next;
    }

    printMap(main);

    unordered_multimap<int, Node *> address;

    for (auto &row : main)
    {
        int value = row.first;
        list<Node *> nodeList = row.second;
        Node *nextNode = nodeList.front();
        Node *randomNode = nodeList.back();
    }
}

int main()
{
    // Example usage
    vector<pair<int, int>> values = {{7, -1}, {13, 0}, {11, 4}, {7, 2}, {1, 0}};
    Node *head = generateRandomLinkedList(values);

    // Print the generated linked list with random pointers
    deepCopy(head);

    // Clean up: Free memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
