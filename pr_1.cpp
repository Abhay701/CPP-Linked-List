// Giveb the head of a linked list, delete every alternate element from the list starting from the second element
// e.g. Input:
// n=6
// List = 1->2->3->4->5->6
// Output:
// 1->3-5

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

void deleteAlternateNode(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);

    Node *head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;

    traverse(head);
    deleteAlternateNode(head);
    traverse(head);
}