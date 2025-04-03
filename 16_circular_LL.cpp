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

    return 0;
}