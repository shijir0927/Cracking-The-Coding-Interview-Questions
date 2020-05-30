/*Question: Remove duplicates from an unsorted linked list.*/

#include <iostream>
#include <unordered_map>
#include <random>
/*Solution:
Remove duplicates from the list using hash table*/

struct Node
{
    int data = 0;
    Node *next = nullptr;
};

void insert(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

static inline int random_range(const int min, const int max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}

void removeDuplicates(Node *head)
{
    if (head == nullptr || (head && (head->next == nullptr)))
    {
        return;
    }
    std::unordered_map<int, int> node_map;
    Node *prev = head;
    Node *curr = head->next;
    node_map[head->data] = 1;
    while (curr != nullptr)
    {
        while (curr && node_map.find(curr->data) != node_map.end())
        {
            curr = curr->next;
        }
        prev->next = curr;
        prev = curr;
        if (curr)
        {
            node_map[curr->data] = 1;
            curr = curr->next;
        }
    }
}

int main()
{

    std::cout << "Method 2 : \n";
    Node *head1 = nullptr;
    for (int i = 0; i < 10; ++i)
    {
        insert(head1, random_range(1, 7));
    }
    printList(head1);
    removeDuplicates(head1);
    printList(head1);
    return 0;
}