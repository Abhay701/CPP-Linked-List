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

    return 0;
}