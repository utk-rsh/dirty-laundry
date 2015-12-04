/**
 * Definition for singly-linked list.
 * struct ListNode {
 * 	int val;
 * 	ListNode *next;
 * 	ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  void recur(ListNode **left, ListNode *right, bool &flag)
  {
	if (right != NULL)
  	recur(left, right->next, flag);
	if (*left == right)
  	return;
	if ((**left).next == right && (**left).val == right->val)
  	return;
	if ((*left)->val != right->val)
  	flag = false;
	(*left) = (*left)->next;
	return;
  }   

  bool isPalindrome(ListNode* head)
  {
	bool ans = true;
	recur(&head, head, ans);
	return ans;
  }
};



