#include <iostream>
#include <stack>

struct Node
{
  char data;
  Node *next;
  Node(char c) : data{c}, next{nullptr} {}
};

void insert(Node *&head, char c)
{
  Node *newNode = new Node(c);
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

void reverse(Node *&head)
{
  if (head == nullptr || (head && (head->next == nullptr)))
  {
    return;
  }
  Node *newHead = nullptr;
  Node *nextNode = nullptr;
  while (head)
  {
    nextNode = head->next;
    head->next = newHead;
    newHead = head;
    head = nextNode;
  }
  head = newHead;
}

bool isPalindromeIter1(Node *head)
{

  // if list is empty or just contains one node.
  if (head == nullptr || head->next == nullptr)
  {
    return true;
  }

  //step1 figure out middle node.
  Node *ptr1 = head;
  Node *ptr2 = head;
  Node *middleNode = nullptr;

  while (ptr2 && ptr1 && ptr1->next)
  {
    ptr1 = ptr1->next->next;
    ptr2 = ptr2->next;
  }

  //in case of odd number of nodes, skip the middle one
  if (ptr1 && ptr1->next == nullptr)
  {
    ptr2 = ptr2->next;
  }

  //reverse the second half of the list
  reverse(ptr2);

  middleNode = ptr2;
  // now compare the two halves
  ptr1 = head;

  while (ptr1 && ptr2 && ptr1->data == ptr2->data)
  {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  //reverse the list again.
  reverse(middleNode);

  if (ptr2 == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isPalindromeIter2(Node *head)
{
  // if list is empty or just contains one node.
  if (head == nullptr || head->next == nullptr)
  {
    return true;
  }

  Node *ptr1 = head;
  Node *ptr2 = head;

  //pushing the first half of list to stack.
  std::stack<Node *> nodeStack;

  while (ptr2 && ptr1 && ptr1->next)
  {
    ptr1 = ptr1->next->next;
    nodeStack.push(ptr2);
    ptr2 = ptr2->next;
  }

  //in case of odd number of nodes, skip the middle one
  if (ptr1 && ptr1->next == nullptr)
  {
    ptr2 = ptr2->next;
  }

  // Now compare the other half of the list with nodes
  // we just pushed in stack

  while (!nodeStack.empty() && ptr2)
  {
    Node *curr = nodeStack.top();
    nodeStack.pop();
    if (curr->data != ptr2->data)
    {
      return false;
    }
    ptr2 = ptr2->next;
  }

  return true;
}

bool isPalindromeRecurHelper(Node *&left, Node *right)
{
  //base case Stop when right becomes nullptr
  if (right == nullptr)
  {
    return true;
  }

  //rest of the list should be palindrome
  bool isPalindrome = isPalindromeRecurHelper(left, right->next);
  if (!isPalindrome)
  {
    return false;
  }

  // check values at current node.
  isPalindrome = (left->data == right->data);

  // move left to next for next call.
  left = left->next;

  return isPalindrome;
}

bool isPalindromeRecur(Node *head)
{
  return isPalindromeRecurHelper(head, head);
}

int main()
{
  Node *head1 = nullptr;
  insert(head1, 'a');
  insert(head1, 'b');
  insert(head1, 'c');
  insert(head1, 'c');
  insert(head1, 'b');
  insert(head1, 'a');
  std::cout << "List 1: ";
  printList(head1);
  if (isPalindromeIter1(head1))
  {
    std::cout << "List 1 is pallindrome list\n";
  }
  else
  {
    std::cout << "List 1 is not a pallindrome list\n";
  }
  std::cout << "List 1: ";
  printList(head1);

  Node *head2 = nullptr;
  insert(head2, 'r');
  insert(head2, 'a');
  insert(head2, 'd');
  insert(head2, 'a');
  insert(head2, 'r');
  std::cout << "List 2: ";
  printList(head2);

  if (isPalindromeIter2(head2))
  {
    std::cout << "List 2 is pallindrome list\n";
  }
  else
  {
    std::cout << "List 2 is not a pallindrome list\n";
  }

  std::cout << "List 2: ";
  printList(head2);

  Node *head = nullptr;
  insert(head, 'a');
  insert(head, 'b');
  insert(head, 'c');
  insert(head, 'b');
  insert(head, 'd');
  std::cout << "List 3: ";
  printList(head);

  if (isPalindromeRecur(head))
  {
    std::cout << "List 3 is pallindrome list\n";
  }
  else
  {
    std::cout << "List 3 is not a pallindrome list\n";
  }
  std::cout << "List 3: ";
  printList(head);
  return 0;
}