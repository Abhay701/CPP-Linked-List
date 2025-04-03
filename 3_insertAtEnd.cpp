#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int v)
    {
        value = v;
        next = NULL;
    }
};

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node *&h, int val)
{
    Node *newNode = new Node(val);
    newNode->next = h;
    h = newNode;
}

void insertAtEnd(Node *h, int val)
{
    if (h == NULL)
    {
        insertAtHead(h, val);
    }

    Node *newNode = new Node(val);
    Node *temp = h;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Now temp is pointing to last node
    temp->next = newNode;
    newNode->next = NULL;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *head = node1;

    cout << "Traversal before insertion:" << endl;
    traverse(head);

    // Use when head is passed by reference
    insertAtHead(head, 45);
    cout << "Traversal after insertion at head:" << endl;
    traverse(head);

    insertAtEnd(head, 55);
    cout << "Traversal after insertion at end:" << endl;
    traverse(head);
}