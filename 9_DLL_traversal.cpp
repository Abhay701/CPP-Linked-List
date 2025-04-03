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

    return 0;
}