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
  ListNode* deleteDuplicates(ListNode* head) 
  {
    ListNode dummy(0);
    ListNode *p = &dummy;
    p->next = head;
    bool skip_flag = 0;
    while (head != NULL && head->next != NULL)
    {
      if (head->val == head->next->val)
      {
        skip_flag = 1;
        head->next = head->next->next;
      }
      else
      {
        if (skip_flag)
          p->next = head->next;
        else
          p = head;
        skip_flag = 0;
        head = head->next;
      }
    }
    if (skip_flag)
      p->next = NULL;
    return dummy.next;       
  }
};