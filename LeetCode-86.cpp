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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL)
            return head;
        ListNode* small = nullptr;
        ListNode* small_start = nullptr;
        ListNode* big = nullptr;
        ListNode* big_start = nullptr;
        ListNode* mover = head;
        while (mover != NULL)
        {
            if (mover->val < x)
            {
                if (small == nullptr)
                {
                    small = new ListNode(mover->val);
                    small_start = small;
                }
                else
                {
                    ListNode *temp = new ListNode(mover->val);
                    small->next = temp;
                    small = small->next;
                }
            }
            else
            {
                if (big == nullptr)
                {
                    big = new ListNode(mover->val);
                    big_start = big;
                }
                else
                {
                    ListNode *temp = new ListNode(mover->val);
                    big->next = temp;
                    big = big->next;
                }
            }
            mover = mover->next;
        }
        if (small == nullptr)
            return big_start;
        small->next = big_start;
        return small_start;
    }
};

