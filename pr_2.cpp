// Find the middle element of the given linked list

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

int traverse(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        cout << temp->value << "->";
        temp = temp->next;
        count++;
    }
    cout << "NULL" << endl;
    return count;
}

void middleElement(Node *h, int pos)
{
    Node *temp = h;
    int i = 1;
    while (temp != NULL)
    {
        if (i == pos)
        {
            cout << temp->value << endl;
        }
        temp = temp->next;
        i++;
    }
}

// or

void middleElementt(Node *h)
{
    Node *slow = h;
    Node *fast = h;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    cout << slow->value;
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

    int middlePos = (traverse(head) + 1) / 2;
    traverse(head);
    middleElement(head, middlePos);
    middleElementt(head);
}