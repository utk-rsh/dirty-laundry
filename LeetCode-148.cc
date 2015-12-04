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
  ListNode* merge(ListNode* a, ListNode* b)
  {
    if (a == NULL) return b;
    if (b == NULL) return a;
    ListNode* head = (a->val < b->val ? a : b);
    ListNode* current;
    if (a->val < b->val)
    {
      current = a;
      a = a->next;
    }
    else
    {
      current = b;
      b = b->next;
    }
    while (a != NULL && b != NULL)
    {
      if (a->val < b->val)
      {
        current->next = a;
        a = a->next;
      }
      else
      {
        current->next = b;
        b = b->next;
      }
      current = current->next;
    }
    if (a != NULL)
      current->next = a;
    else if (b != NULL)
        current->next = b;
      return head;
  }

  ListNode* mergeSort(ListNode* head)
  {
    if (head == NULL || head->next == NULL) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    fast = fast->next;
    while (fast != NULL && fast->next != NULL)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode* temp = slow->next;
    slow->next = NULL;
    head = mergeSort(head);
    temp = mergeSort(temp);
    head = merge(head, temp);
    return head;
  }   

  ListNode* sortList(ListNode* head) 
  {
     head = mergeSort(head);
     return head; 
  }
};


