#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        int counter = 1;
        stack<ListNode*> holder;
        ListNode* current = head;
        ListNode* pre_flip = NULL;
        ListNode* to_return = head;
        while (counter < m)
        {
          pre_flip = current;
          current = current->next;
          counter++;
        }
        while (counter <= n)
        {
          cout << "pushing on counter " << current->val << endl;
          holder.push(current);
          if (counter != n)
            current = current->next;
          counter++;
        }
        if (m == 1)
          to_return = current;
        ListNode* post_flip;
        post_flip = current->next;
        cout << (pre_flip == NULL) << endl;
        cout << to_return->val << endl;
        if (pre_flip == NULL)
          pre_flip = to_return;
        while (holder.empty() == 0)
        {
          cout << "holder size is " << holder.size() << endl;
          ListNode* temp = holder.top();
          cout << "temp val is " << temp->val << endl;
          pre_flip->next = temp;
          cout << "setting next value of " << pre_flip->val << endl;
          pre_flip = pre_flip->next;
          holder.pop();
        }
        pre_flip->next = post_flip;
        return to_return;
    }
};

int main()
{
  ListNode a(1);
  ListNode b(2);
  ListNode c(3);
//  a.next = &b;
//  b.next = &c;
  Solution obj;
  ListNode* ans = obj.reverseBetween(&a, 1, 1);
  cout << "First element of list is " << ans->val << endl;
//  cout << "Second element of list is " << ans->next->val << endl;
//  cout << "Third element of list is " << ans->next->next->val << endl;
  return 0;
}
