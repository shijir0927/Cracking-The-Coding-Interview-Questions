/**

 * Question: Implement an algorithm to delete a node in the middle of a singly linked list.
 * We are given pointer to that node.
 *
 * Solution:
 * we can copy the data of next node to
 * the pointed node and then remove the next node.
 */

#include <iostream>

struct Node
{
    char data;
    Node *next;
    Node(char c) : data{c}, next{nullptr} {}
};

void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

void deleteNode(Node *node)
{
    if (node == nullptr || node->next == nullptr)
    {
        return;
    }
    Node *nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
}

int main()
{
    Node *head = new Node('a');
    head->next = new Node('b');
    head->next->next = new Node('c');
    head->next->next->next = new Node('d');
    head->next->next->next->next = new Node('e');
    std::cout << "List before deletion:\n";
    printList(head);
    std::cout << "Deleting node containing data as 'c'\n";
    deleteNode(head->next->next);
    std::cout << "List after deletion:\n";
    printList(head);
    return 0;
}