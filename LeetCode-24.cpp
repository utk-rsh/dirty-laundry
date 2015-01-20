#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

struct ListNode
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode* mover = head;
        if (mover == NULL)
            return mover;
        if (mover->next == NULL)
            return mover;
        ListNode* toReturn = head->next;
        ListNode* pretemp;
        while ((mover != NULL) && (mover->next != NULL))
        {
            ListNode* temp = mover->next->next;
            mover->next->next = mover;
            if ((temp != NULL) && (temp->next != NULL))
                mover->next = temp->next;
            else
                mover->next = temp;
            mover = temp;
        }
        return toReturn;
    }
};
