#include <iostream>
#include "LinkedList.h"
#include <string>
using namespace std;

void LinkedList::SortByInsertion()
{

    if (head->next)
    { // only sort if the list has more than 1 item
        Train *currentPtr = head->next;
        Train *prevPtr = head;

        Train *prevPrevPtr = nullptr;
        prevPrevPtr->next = prevPtr;

        while (currentPtr != nullptr)
        {
            for (prevPtr->next = currentPtr; prevPtr->value > currentPtr->value; prevPtr = prevPrevPtr)
            {
                currentPtr = prevPtr;
            }

            currentPtr = currentPtr->next;
        }
        display();
    }
    else
    {
        display();
    }
}

LinkedList::LinkedList(LinkedList &list)
{ // Constructor that copies the list
    Train *nodePtr = list.head;
    cout << "The copied list is: " << nodePtr->value << " ";
    while (nodePtr->next)
    {
        nodePtr = nodePtr->next;
        cout << nodePtr->value << " ";
    }
    cout << endl;
}
void LinkedList::append(double num)
{ // adds a item to the end of the list
    Train *newTrain;
    Train *nodPtr;

    newTrain = new Train;
    newTrain->value = num;
    newTrain->next = nullptr;

    if (!head)
    {
        head = newTrain;
    }
    else
    {
        nodPtr = head;

        while (nodPtr->next)
        {
            nodPtr = nodPtr->next;
        }
        nodPtr->next = newTrain;
    }
}
void LinkedList::insert(double num)
{
    Train *newTrain;
    Train *nodPtr;
    Train *previous = nullptr;

    newTrain = new Train;
    newTrain->value = num;
    newTrain->next = nullptr;

    if (!head || head->value > num)
    {
        head->value = newTrain->value;
    }
    else
    {
        nodPtr = head;
        while (nodPtr != nullptr && nodPtr->value < num)
        {
            previous = nodPtr;
            nodPtr = nodPtr->next;
        }
        if (nodPtr->value > num)
        {
            previous->next = newTrain;
            newTrain->next = nodPtr;
        }
    }
}
void LinkedList::erase(double num)
{
    Train *nodPtr;
    Train *previous = nullptr;

    if (!head)
    {
        return;
    }

    if (head->value == num)
    {
        nodPtr = head->next;
        delete head;
        head = nodPtr;
    }
    else
    {

        nodPtr = head;
        while (nodPtr != nullptr && nodPtr->value != num)
        {
            previous = nodPtr;
            nodPtr = nodPtr->next;
        }
        previous->next = nodPtr->next;
        delete nodPtr;
    }
}
void LinkedList::display() const
{
    Train *nodPtr;

    nodPtr = head;

    while (nodPtr)
    {
        cout << nodPtr->value << " ";
        nodPtr = nodPtr->next;
    }
    cout << endl;
}
void LinkedList::reverse(LinkedList &list)
{
    Train *nodePtr = list.head;
    Train *previous = nullptr;
    Train *next = nullptr;

    while (nodePtr != nullptr)
    {
        next = nodePtr->next;
        nodePtr->next = previous;
        previous = nodePtr;
        nodePtr = next;
    }
    list.head = previous;
}
void LinkedList::printReverse(LinkedList &list)
{
    Train *nodePtr = list.head;
    while (nodePtr != nullptr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
double LinkedList::operator[](int pos)
{
    Train *nodPtr = head;
    for (int i = 0; i < pos - 1 && nodPtr; i++, nodPtr = nodPtr->next)
        ;
    double val;
    if (nodPtr)
    {
        val = nodPtr->value;
    }
    else
    {
        val = -1.1;
    }
    return val;
}
void LinkedList::search(double num)
{
    Train *nodeptr = head;
    int i = 1;

    while (nodeptr->value != num)
    {
        nodeptr = nodeptr->next;
        i++;
    }
    cout << "The number you searched for is " << i << "th number in the list" << endl;
}
void LinkedList::insertByPosition(int pos, int val)
{
    Train *nodePtr = nullptr;
    Train *newPtr = new Train;
    newPtr->value = val;
    newPtr->next = nullptr;
    Train *next = nullptr;

    int counter = 1;

    if (pos == 0)
    {
        newPtr->next = head->next;
        head = newPtr;
    }
    else
    {
        nodePtr = head;
        while (counter != pos)
        {
            nodePtr = nodePtr->next;
            counter++;
        }
        next = nodePtr->next;
        nodePtr->next = newPtr;
        newPtr->next = next;
    }
}
void LinkedList::eraseByPosition(int pos)
{
    Train *nodPtr = head;
    Train *headPtr = nullptr;
    Train *previous = nullptr;
    for (int i = 0; i < pos && nodPtr; i++, previous = nodPtr, nodPtr = nodPtr->next)
        ;
    if (!head)
    {
        return;
    }
    else if (pos == 0)
    {
        headPtr = head->next;
        delete head;
        head = headPtr;
    }
    else if (nodPtr && nodPtr != nullptr)
    {
        previous->next = nodPtr->next;
        delete nodPtr;
    }
    else
    {
        cout << "I did nothing" << endl;
    }
}
LinkedList::~LinkedList()
{
    Train *nodePtr;  // To traverse the list
    Train *nextNode; // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}
