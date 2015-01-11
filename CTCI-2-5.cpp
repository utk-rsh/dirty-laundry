// Cracking the Coding Interview: Ques 2.5

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

node* add(node* a1, node* a2, int carry)
{
    node* result = new node;
    node* begin = result;
    while ((a1 != NULL) && (a2 != NULL))
    {
        int temp = a1->data + a2->data + carry;
        result->data = temp%10;
        carry = temp/10;
        node* next = new node;
        result->next = next;
        result = result->next;
        a1 = a1->next;
        a2 = a2->next;
    }
    if (a2 == NULL)
    {
        node* temp;
        temp = a2;
        a2 = a1;
        a1 = temp;
    }
    if (a1 == NULL)
    {
        while (a2 != NULL)
        {
            int temp = a2->data + carry;
            result->data = temp%10;
            carry = temp/10;
            if (carry == 0)
            {
                result->next = a2->next;
                return begin;
            }
            node* next = new node;
            result->next = next;
            result = result->next;
            a2 = a2->next;
        }
        if (carry != 0)
            result->data = carry;
        else
            delete(result);
    }
    return begin;
}

int main()
{
node* begin = new node;
begin->data = 1;
node* temp = new node;
temp->data = 5;
begin->next = temp;
node* temp1 = new node;
temp1->data = 5;
temp->next = temp1;
//  Numbers are 551 and 88.
node * temp2 = new node;
temp2->data = 8;
//temp1->next = temp2;
node * temp3 = new node;
temp3->data = 8;
temp2->next = NULL;
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
mover = add(begin, temp2, 0);
cout << "printing the list: " << endl;
while (mover != NULL)
{
    cout << mover->data << "  ";
    mover = mover->next;
}
cout << endl;
}
