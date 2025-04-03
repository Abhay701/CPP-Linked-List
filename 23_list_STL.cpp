#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {1, 2, 3, 4};
    // list<int>::iterator itr=l1.begin();
    // or
    auto itr = l1.begin();
    cout << *itr << endl;

    auto rev_itr = l1.rbegin();
    cout << *rev_itr << endl;

    advance(itr, 2);
    cout << *itr << endl;

    // Range based traversal of list
    for (auto num : l1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Traversal through iterators
    for (auto itr = l1.begin(); itr != l1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // Reverse traversal of list
    for (auto itr = l1.rbegin(); itr != l1.rend(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // Inserting elements
    itr = l1.begin();
    advance(itr, 2);
    l1.insert(itr, 2, 5);

    // Traversal through iterators
    for (auto itr = l1.begin(); itr != l1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    itr = l1.begin();
    auto s_itr = l1.begin();
    auto e_itr = l1.begin();
    advance(e_itr, 2);
    l1.insert(itr, s_itr, e_itr);
    // Traversal through iterators
    for (auto itr = l1.begin(); itr != l1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // Deleting elements
    auto s_itrr = l1.begin();
    auto e_itrr = l1.begin();
    advance(s_itrr, 2);
    advance(e_itrr, 6);
    l1.erase(s_itrr, e_itrr);

    // Traversal through iterators
    for (auto itr = l1.begin(); itr != l1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    auto itrr = l1.begin();
    l1.erase(itrr);
    // Traversal through iterators
    for (auto itr = l1.begin(); itr != l1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}