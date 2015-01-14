#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    stack<ListNode*> st;
    void reorderList(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
            else
                break;
            slow = slow->next;
        }
      //  cout << "slow stopped at " << slow->val << endl;
        ListNode* cop = slow;
        while (slow != NULL)
        {
            slow = slow->next;
            if (slow == NULL)
                break;
            st.push(slow);
        }
        if (cop != NULL)
            cop->next = NULL;
        ListNode* start = head;
    //    cout << "is stack empty " << st.empty() << endl;
        while (st.empty() == false)
        {
            ListNode* temp = st.top();
         //   cout << "start val " << start->val << endl;
         //   cout << "temp val " << temp->val << endl;
            st.pop();
            temp->next = start->next;
            start->next = temp;
            start = temp->next;
        }
        return;
    }
};

int main()
{
ListNode* a = new ListNode(1);
ListNode* b = new ListNode(2);
ListNode* c = new ListNode(3);
ListNode* d = new ListNode(4);
//a->next = b;
//b->next = c;
//c->next = d;
Solution obj;
obj.reorderList(a);
cout << a->val << endl;
//cout << a->next->val << endl;
//cout << a->next->next->val << endl;
//cout << a->next->next->next->val << endl;
return 0;
}
