/**
 *  Question: Write code to partition linked list around a value x, such that
 *  nodes less than x come before all the nodes greater than or equal to x.
 *
 *  Solution:
 *  Start with first node, and add every thing bigger or equal to x at tail
 *  and smaller values at head.
 */

#include <iostream>
#include <random>

struct Node
{
    int data;
    Node *next;
    Node(int d) : data{d}, next{nullptr} {}
};

void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
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

/* We start with a new list. Elements bigger than the pivot element are put at the tail list
 and elements smaller are put at the head list*/
Node *partition(Node *listhead, int x)
{
    Node *head = nullptr;
    Node *headInitial = nullptr; /*The initial node of list head*/
    Node *tail = nullptr;
    Node *tailInitial = nullptr; /*The initial node of list tail*/
    Node *curr = listhead;
    while (curr != nullptr)
    {
        Node *nextNode = curr->next;
        if (curr->data < x)
        {
            if (head == nullptr)
            {
                head = curr;
                headInitial = head;
            }
            //insert curr node to head list
            head->next = curr;
            head = curr;
        }
        else
        {
            if (tail == nullptr)
            {
                tail = curr;
                tailInitial = tail;
            }
            // insert curr node to tail list
            tail->next = curr;
            tail = curr;
        }
        curr = nextNode;
    }
    head->next = tailInitial; /*Now, we connect the head list to tail list.*/
    tail->next = nullptr;
    return headInitial;
}

int main()
{
    Node *head = nullptr;
    for (int i = 0; i < 10; ++i)
    {
        insert(head, rand() % 9);
    }
    std::cout << "List before partition around 5:\n";
    printList(head);
    std::cout << "List after partition around 5:\n";
    printList(partition(head, 5));
    return 0;
}