#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int d)
    {
        value = d;
        next = NULL;
    }
};

void traversal(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->value << "->";
        temp = temp->next;
    } while (temp != head);
    cout << head->value << endl;
}

void insertAtStart(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void insertAtMiddle(Node *&head, int val, int pos)
{
    if (pos == 1)
    {
        insertAtStart(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int i = 1;
    while (i < (pos - 1))
    {
        temp = temp->next;
        i++;
    }
    Node *next = temp->next;
    temp->next = newNode;
    newNode->next = next;
}

void deleteAtStart(Node *&head)
{
    if (head == NULL) // Check if the list is empty
        return;

    if (head->next == head) // Only one node in the list
    {
        delete head;
        head = NULL;
        return;
    }

    // Find the last node (the node pointing to head)
    Node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }

    // Update the head and delete the first node
    Node *deleteNode = head;
    head = head->next;
    tail->next = head;

    delete deleteNode;
}

void deleteAtEnd(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = head;

    delete deleteNode;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;

    Node *head = n1;

    traversal(head);

    insertAtStart(head, 8);
    cout << "After insertion at start:" << endl;
    traversal(head);

    insertAtEnd(head, 10);
    cout << "After insertion at end:" << endl;
    traversal(head);

    insertAtMiddle(head, 15, 2);
    cout << "After insertion at middle:" << endl;
    traversal(head);

    deleteAtStart(head);
    cout << "After deletion at start:" << endl;
    traversal(head);

    deleteAtEnd(head);
    cout << "After deletion at end:" << endl;
    traversal(head);

    return 0;
}