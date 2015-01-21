#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;
/*
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
*/

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        map<int, int> lookup;
        ListNode* mover = head;
        if (head == NULL)
            return head;
        lookup[head->val] = 1;
        int c = 2;
        while (mover != NULL)
        {
            if ((mover->next != NULL) && (lookup.find(mover->next->val) == lookup.end()))
            {
                lookup[mover->next->val] = c;
                c++;
                mover = mover->next;
            }
            else if (mover->next == NULL)
                return head;
            else
                mover->next = mover->next->next;
        }
        return head;
    }
};
