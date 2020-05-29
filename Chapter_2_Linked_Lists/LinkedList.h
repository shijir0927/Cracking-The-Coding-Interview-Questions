#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{

private:
    struct Train
    {
        double value;
        Train *next;
    };

    Train *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    LinkedList(LinkedList &list);

    ~LinkedList();
    //bool empty();
    void append(double);
    void insert(double);
    void erase(double);
    void display() const;
    double operator[](int);
    void reverse(LinkedList &list);
    void printReverse(LinkedList &list);
    void search(double num);
    void insertByPosition(int pos, int val);
    void eraseByPosition(int pos);
    void SortByInsertion();
};

#endif