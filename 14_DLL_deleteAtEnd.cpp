#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int d)
    {
        value = d;
        next = NULL;
        prev = NULL;
    }
};

void forwardTraversal(Node *head)
{
    Node *temp = head;
    cout << "NULL<-->";
    while (temp != NULL)
    {
        cout << temp->value << "<-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void backwardTraversal(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *tail = temp;

    cout << "NULL<-->";
    while (tail != NULL)
    {
        cout << tail->value << "<-->";
        tail = tail->prev;
    }
    cout << "NULL" << endl;
}

void insertionAtStart(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    temp->prev = newNode;
    newNode->next = temp;
    head = newNode;
}

void insertAtEnd(Node *head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtMiddle(Node *&head, int v, int pos)
{
    Node *newNode = new Node(9);
    if (pos == 1)
    {
        insertionAtStart(head, v);
        return;
    }
    Node *temp = head;
    int i = 1;
    while (i < (pos - 1))
    {
        temp = temp->next;
        i++;
    }

    Node *nextNode = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}

void deleteAtStart(Node *&head)
{
    if (head->next == NULL)
    {
        delete head;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    // or
    // free(temp);
}

void deleteAtEnd(Node *&head)
{
    if (head->next == NULL)
    {
        free(head);
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = NULL;
    delete deleteNode;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);

    // n1->prev = NULL;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    // n3->next = NULL;

    Node *head = n1;
    forwardTraversal(head);
    backwardTraversal(head);

    insertionAtStart(head, 5);
    cout << "After insertion at start:" << endl;
    forwardTraversal(head);
    backwardTraversal(head);

    insertAtEnd(head, 8);
    cout << "After insertion at end:" << endl;
    forwardTraversal(head);
    backwardTraversal(head);

    insertAtMiddle(head, 9, 2);
    cout << "After insertion at Middle:" << endl;
    forwardTraversal(head);
    backwardTraversal(head);

    deleteAtStart(head);
    cout << "After deletion at start:" << endl;
    forwardTraversal(head);
    backwardTraversal(head);

    deleteAtEnd(head);
    cout << "After deletion at end:" << endl;
    forwardTraversal(head);
    backwardTraversal(head);

    return 0;
}