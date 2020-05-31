/*Implement an algorithm to find the kth to last element of a singly linked list.
 We can assume we are not provided the length of the list.*/

#include <iostream>

/*Maintain an index to keep track of node.
 Solve the problem for n-1 nodes and add 1 to index.
 Since each parent call is adding 1, when counter reaches k,
 we have reached length-k node from start, which is kth node from last.*/
struct Node
{
    int data;
    Node *next;
    Node(int d) : data{d}, next{nullptr} {}
};

void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void deleteList(Node *&head)
{
    Node *nextNode;
    while (head)
    {
        nextNode = head->next;
        delete (head);
        head = nextNode;
    }
}

void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

Node *kthToLastHelper(Node *head, int k, int &i)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *node = kthToLastHelper(head->next, k, i);
    i = i + 1;
    //if we have solved problem k times from last.
    if (i == k)
    {
        return head;
    }
    return node;
}

Node *kthToLastRecursive(Node *head, int k)
{
    int i = 0;
    return kthToLastHelper(head, k, i);
}

int main()
{
    Node *head = nullptr;
    for (int i = 7; i > 0; i--)
    {
        insert(head, i);
    }
    std::cout << "List: ";
    printList(head);

    std::cout << "4th node from last (Recursive) : ";
    Node *node4 = kthToLastRecursive(head, 4);
    if (node4 != nullptr)
    {
        std::cout << node4->data << std::endl;
    }
    else
    {
        std::cout << "NULL NODE\n";
    }

    deleteList(head);

    return 0;
}