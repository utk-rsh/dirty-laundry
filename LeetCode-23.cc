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
    if (a == NULL)
      return b;
    if (b == NULL)
      return a;
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

  ListNode* mergeKLists(vector<ListNode*>& lists) 
  {
    if (lists.size() == 0)
      return NULL;
    vector<ListNode*> aux;
    auto first = &lists;
    auto second = &aux;
    while (first->size() != 1)
    {
      for (int i = 0; i < first->size(); i += 2)
      {
        if (i + 1 != first->size())
          second->push_back(merge(first->at(i), first->at(i+1)));
        else
          second->push_back(first->at(i));
      }
      auto temp = first;
      first = second;
      second = temp;
      second->clear();
     }
     return first->at(0);
  }
};