#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
      ListNode* l1_mover = l1;
      ListNode* l2_mover = l2;
      int carry = 0;
      ListNode* ans = new ListNode(0);
      ListNode* ans_mover = ans;
      while ((l1_mover != NULL) || (l2_mover != NULL))
      {
        int digit_sum = carry;
        if (l1_mover != NULL)
        {
            digit_sum += l1_mover->val;
            l1_mover = l1_mover->next;
        }
        if (l2_mover != NULL)
        {
          digit_sum += l2_mover->val;
          l2_mover = l2_mover->next;
        }
        ans_mover->val = digit_sum % 10;
        carry = digit_sum / 10;
        if ((l1_mover != NULL) || (l2_mover != NULL))
        {
          ListNode* element = new ListNode(0);
          ans_mover->next = element;
          ans_mover = ans_mover->next;
        }

      }
      if (carry != 0)
      {
        ListNode *last_one = new ListNode (carry);
        ans_mover->next = last_one;
      }
      return ans;
    }
};

int main()
{
  ListNode a1(8);
  ListNode b1(7);
  ListNode b2(1);
  ListNode b3(9);
  b1.next = &b2;
  b2.next = &b3;
  Solution object;
  ListNode* ans = object.addTwoNumbers(&a1, &b1);
  cout << "printing ans " << endl;
  while (ans != NULL)
  {
    cout << ans->val << " " << endl;
    // cout << ans->val << " "; // if this line is used, instead of the above one,
    // the program terminates with an error message. It doesn't give an error if the other line
    // is used.
    ans = ans->next;
  }
}
