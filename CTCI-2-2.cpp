// Cracking the Coding Interview: Ques 2.2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

struct node
{
int data;
node* next;
};

void k2last(node* current, int k) // k = 1 means last
{
// assumed that list contains atleast 2 elements. If not, checks can be introduced.
    if (k < 1)
        return;
    node* slow = current;
    node* fast = current;
    for (int i = 0; i < k; i++)
    {
  //      cout << "The element currently on is " << fast->data << endl;
        fast = fast->next;
        if (fast == NULL) // If first element of the list has to be deleted.
        {
    //        cout << "The element being removed is " << current->next->data << endl << endl;
            current->data = current->next->data;
            current->next = current->next->next;
            return;
        }
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
  //  cout << "The element being removed is " << slow->next->data << endl << endl;
    slow->next = slow->next->next;
    return;
}

int main()
{
node* begin = new node;
begin->data = 1;
node* temp = new node;
temp->data = 2;
begin->next = temp;
node* temp1 = new node;
temp1->data = 3;
temp->next = temp1;
node * temp2 = new node;
temp2->data = 98;
temp1->next = temp2;
node * temp3 = new node;
temp3->data = 4;
temp2->next = temp3;
node* mover = begin;
cout << "printing the list before removal: ";
while (mover != NULL)
{
    cout << mover->data << "  ";
    mover = mover->next;
}
cout << endl;
cout << endl;
k2last(begin, 3);
cout << "One element has been removed" << endl;
k2last(begin, 1);
k2last(begin, 2);
k2last(begin, 1);
cout << "printing the list: ";
mover = begin;
while (mover != NULL)
{
    cout << mover->data << "  ";
    mover = mover->next;
}
cout << endl;
}
