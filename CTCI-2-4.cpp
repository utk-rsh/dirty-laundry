// Cracking the Coding Interview: Ques 2.4

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

node* partition_x(node* current, int x)
{
node* small = NULL;
node* small_start;
node* big = NULL;
node* big_start;
node* mover = current;
while (mover != NULL)
{
    if (mover->data < x)
    {
        if (small == NULL)
        {
            small = new node;
            small->data = mover->data;
            small_start = small;
        }
        else
        {
            node *temp = new node;
            temp->data = mover->data;
            small->next = temp;
            small = small->next;
        }
    }
    else
    {
        if (big == NULL)
        {
            big = new node;
            big->data = mover->data;
            big_start = big;
        }
        else
        {
            node* temp = new node;
            temp->data = mover->data;
            big->next = temp;
            big = big->next;
        }
    }
    mover = mover->next;
}
if (small == NULL)
    return big_start;
else if (big_start == NULL)
    return small_start;
else
    small->next = big_start;
return small_start;
}

int main()
{
node* begin = new node;
begin->data = 1;
node* temp = new node;
temp->data = 21;
begin->next = temp;
node* temp1 = new node;
temp1->data = 3;
temp->next = temp1;
node * temp2 = new node;
temp2->data = 98;
temp1->next = temp2;
node * temp3 = new node;
temp3->data = 6;
temp2->next = temp3;
node* mover = begin;
cout << "printing the list before paritioning: ";
while (mover != NULL)
{
    cout << mover->data << "  ";
    mover = mover->next;
}
cout << endl;
cout << endl;
mover = partition_x(begin, 19);
cout << "printing the list: " << endl;
while (mover != NULL)
{
    cout << mover->data << "  ";
    mover = mover->next;
}
cout << endl;
}
