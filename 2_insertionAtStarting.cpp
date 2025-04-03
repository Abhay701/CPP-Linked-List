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

// Parameter Type: head is passed by value.
// Behavior: A copy of the head pointer is passed to the function. Any changes made to head inside the function only affect this copy, not the original head outside the function.
// Modification: Changes to head inside this function do not persist after the function call because they are applied to the copy.
// Node *insertAtHead(Node *head, int val)
// {
//     Node *newNode = new Node(val);
//     newNode->next = head;
//     head = newNode;
//     return head;
// }

// or
// Parameter Type: head is passed by reference.
// Behavior: A reference to the original head pointer is passed to the function. Any changes made to head inside the function directly affect the original head in the calling function.
// Modification: Changes to head persist after the function call because head is a reference to the original pointer.
// Use Case: This version is useful when you want the function to modify the original head pointer without needing to return and reassign it.
void insertAtHead(Node *&h, int val)
{
    Node *newNode = new Node(val);
    newNode->next = h;
    h = newNode;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2; 
    Node *head = node1;

    cout << "Traversal before insertion:" << endl;
    traverse(head);

    // Use when we pass head by value
    // head = insertAtHead(head, 45);

    // Use when head is passed by reference
    insertAtHead(head, 45);
    cout << "Traversal after insertion:" << endl;
    traverse(head);
}