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
        return;
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

void insertAtMiddle(Node *&h, int val, int pos)
{
    if (pos == 1)
    {
        insertAtHead(h, val); // This will now correctly modify the original `head`
        return;
    }

    Node *temp = h;
    Node *newNode = new Node(val);
    int i = 1;
    while (i < (pos - 1))
    {
        temp = temp->next;
        i++;
    }

    // Now thw temp is pointing to the node that should come before new node
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtFirst(Node *&h)
{
    if (h == NULL)
    {
        return;
    }
    Node *temp = h;
    h = h->next;
    // or
    // h = temp->next;
    free(temp);
}

void deleteFromEnd(Node *&h)
{

    if (h == NULL)
    {
        return;
    }
    if (h->next == NULL)
    {
        deleteAtFirst(h);
        return;
    }

    Node *temp = h;
    while ((temp->next)->next != NULL)
    {
        temp = temp->next;
    }
    Node *lastNode = temp->next;
    temp->next = NULL;
    free(lastNode);
}

void deleteAtMiddle(Node *&h, int pos)
{
    if (pos == 1)
    {
        deleteAtFirst(h);
        return; // Rest of the will not execute
    }
    Node *temp = h;
    int i = 1;
    while (i < (pos - 1))
    {
        temp = temp->next;
        i++;
    }
    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
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

    // Insert 12 at given position
    insertAtMiddle(head, 12, 1);
    insertAtMiddle(head, 15, 3);
    cout << "Traversal after insertion at middle position:" << endl;
    traverse(head);

    deleteAtFirst(head);
    cout << "Traversal after deletion of first node:" << endl;
    traverse(head);

    deleteFromEnd(head);
    cout << "Traversal after deletion of last node:" << endl;
    traverse(head);

    deleteAtMiddle(head, 3);
    cout << "Traversal after deletion of any middle node:" << endl;
    traverse(head);
}