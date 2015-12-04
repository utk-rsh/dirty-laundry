/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
  {
    if (headA == NULL || headB == NULL)
      return NULL;
    int la = 0;
    ListNode *temp = headA;
    while (temp != NULL)
    {
      la++;
      temp = temp->next;
    }
    temp = headB;
    int lb = 0;
    while (temp != NULL)
    {
      lb++;
      temp = temp->next;
    }
    ListNode *tempa = headA;
    ListNode *tempb = headB;
    if (la < lb)
    {
      tempa = headB;
      tempb = headA;
    }
    int diff = abs(la - lb);
    while (diff > 0)
    {
      diff--;
      tempa = tempa->next;
    }
    while (tempa != NULL && tempa != tempb)
    {
      tempa = tempa->next;
      tempb = tempb->next;
    }
    return tempa;
  }
};
