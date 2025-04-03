#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int v)
    {
        value = v;
        prev = NULL;
        next = NULL;
    }
};

void traversalForward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void traversalBackward(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *tail = temp;

    while (tail != NULL)
    {
        cout << tail->value << "<->";
        tail = tail->prev;
    }
    cout << "NULL" << endl;
}

void reverse(Node *&head)
{
    Node *previous = NULL;
    Node *current = head;

    while (current != NULL)
    {
        previous = current->prev;      // Save the current previous pointer
        current->prev = current->next; // Swap prev and next pointers
        current->next = previous;
        current = current->prev; // Move to the next node in the original list
    }

    head = previous->prev; // Previous was pointing to the new head's next
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    n1->prev = NULL;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    n5->next = NULL;

    Node *head = n1;

    cout << "Forward traversal:" << endl;
    traversalForward(head);
    cout << "Backward traversal:" << endl;
    traversalBackward(head);
    reverse(head);
    cout << endl
         << "Doubly linked list is reversed:" << endl;
    cout << "Forward traversal:" << endl;
    traversalForward(head);
    cout << "Backward traversal:" << endl;
    traversalBackward(head);
    return 0;
}