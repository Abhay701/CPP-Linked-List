// Split a circular link list into two halves
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

void split(Node *&head, Node *&head1, Node *&head2)
{
    int count = 0;
    Node *temp = head;
    do
    {
        temp = temp->next;
        count++;
    } while ((temp != head));

    cout << "Length = " << count << endl;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    head1 = head;
    head2 = slow->next;
    slow->next = head1;
    if (count % 2 == 0) // Even number of nodes in original linked list
    {
        fast->next->next = head2;
    }
    else
    { // Odd number of nodes in original linked list
        fast->next = head2;
    }
}

// void split(Node *&head, Node *&head1, Node *&head2)
// {
//     if (head == NULL) // If list is empty
//         return;

//     Node *slow = head;
//     Node *fast = head;

//     // Use the slow-fast pointer technique to find the midpoint
//     while (fast->next != head && fast->next->next != head)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // Set the heads of the two halves
//     head1 = head;
//     head2 = slow->next;

//     // Make the first half circular
//     slow->next = head1;

//     // Make the second half circular
//     if (fast->next == head) // Odd number of nodes
//     {
//         fast->next = head2;
//     }
//     else // Even number of nodes
//     {
//         fast->next->next = head2;
//     }
// }

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n1;

    Node *head = n1;

    Node *head1 = NULL;
    Node *head2 = NULL;
    traversal(head);

    split(head, head1, head2);
    traversal(head1);
    traversal(head2);

    return 0;
}