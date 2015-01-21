#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        int length = 0;
        ListNode *mover = head;
        while (mover)
        {
            length++;
            mover = mover->next;
        }
        mover = head;
        int c = 1;
        k = k%length;
        if (k == 0)
            return head;
        while (length - c >= k + 1)
        {
            c++;
            mover = mover->next;
        }
        ListNode* other = head;
        ListNode* toReturn = mover->next;
        while(other->next)
            other = other->next;
        other->next = head;
        mover->next = nullptr;
        return toReturn;
    }
};

int main()
{
ListNode a(1);
ListNode b(2);
ListNode c(3);
a.next = &b;
b.next = &c;
Solution obj;
ListNode* ans = obj.rotateRight(&a,1);
cout << "ans 0 is " << ans->val << endl;
cout << "ans is " << (ans->val) << " " << ans->next->val << "  " << ans->next->next->val << endl;
return 0;
}
