#include <iostream>
#include <cmath>

struct Node
{
    int data;
    Node *next;
    Node(int d) : data{d}, next{nullptr} {}
};

void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int listLen(Node *head)
{
    int count = 0;
    while (head)
    {
        head = head->next;
        count++;
    }
    return count;
}

Node *intersectionPoint(Node *head1, Node *head2)
{
    int len1 = listLen(head1);
    int len2 = listLen(head2);
    //figure out the bigger list ( and smaller )
    //ptr points to bigger list, let us move the difference
    //between the two.
    Node *ptr1 = (len1 > len2) ? head1 : head2;
    Node *ptr2 = (len1 > len2) ? head2 : head1;
    int i = 0;
    while (i < std::abs(len1 - len2) && ptr1)
    {
        ptr1 = ptr1->next;
        ++i;
    }
    //Now we have equal nodes to travel on both the nodes
    // traversing and comparing the pointers.

    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return nullptr;
}

int main()
{
    Node *list1 = new Node(3);
    list1->next = new Node(6);
    list1->next->next = new Node(9);
    list1->next->next->next = new Node(12);
    list1->next->next->next->next = new Node(15);
    list1->next->next->next->next->next = new Node(18);

    Node *list2 = new Node(7);
    list2->next = new Node(10);
    list2->next->next = list1->next->next->next;

    printList(list1);
    printList(list2);

    Node *intersectingNode = intersectionPoint(list1, list2);
    if (intersectingNode)
    {
        std::cout << "Intersecting Node of lists is :" << intersectingNode->data << std::endl;
    }
    else
    {
        std::cout << "Lists do not interset" << std::endl;
    }
    return 0;
}