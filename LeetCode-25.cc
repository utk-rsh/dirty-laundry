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
 ListNode* rev(ListNode *tail, ListNode *head, int k)
  {
    if (k == 0 || tail == NULL)
      return head;
    ListNode* temp = tail->next;
    tail->next = head;
    k--;
    return rev(temp, tail, k);
  }
  
  ListNode* reverseList(ListNode* head, int k) 
  {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode* tail = head->next;
    head->next = NULL;
    return rev(tail, head, k-1);
  }

  ListNode* reverseKGroup(ListNode* head, int k) 
  {
    ListNode dummy(0);
    ListNode* p = &dummy;
    p->next = head;
    ListNode * front = p;
    ListNode * rever = head; 
    ListNode * mover = head;
    while (mover != NULL)
    {
      int count = 0;
      while (count < k)
      {
        if (mover == NULL) break;
        front = mover;
        mover = mover->next;
        count++;
      }
      if (count < k)
      {
        p->next = rever;
        break;
      }
      //cout << "calling reverse on " << rever->val << endl;
      reverseList(rever, k);
      //cout << "rever " << rever->val << endl;
      //cout << "rever next " << rever->next << endl;
      //cout << "front " << front->val << endl;
      //cout << "p " << p->val << endl;
      p->next = front;
      p = rever;
      front = rever;
      rever = mover;
    }
    return dummy.next;
  }
};


