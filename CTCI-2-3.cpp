// Cracking the Coding Interview: Ques 2.3

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

void del_middle(node* current)
{
// Assuming that the length of the list is atleast 3, so that there is one element after the middle element
current->data = current->next->data;
current->next = current->next->next;
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
del_middle(temp1);
cout << "printing the list: ";
mover = begin;
while (mover != NULL)
{
    cout << mover->data << "  ";
    mover = mover->next;
}
cout << endl;
}
