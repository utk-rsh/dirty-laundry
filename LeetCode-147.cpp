  #include <iostream>
  #include <cmath>
  #include <string>
  #include <vector>
  #include <map>

  using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  class Solution {
  public:
      ListNode *insertionSortList(ListNode *head)
      {
        int len = 0;
        ListNode* mover = head;
        while (mover != NULL)
        {
          mover = mover->next;
          len++;
        }
        int moved = 0;
        mover = head;
       // cout << "length is " << len << endl;
        while (len > 0)
        {
          ListNode* temp_max = head;
          mover = head;
          moved = 0;
          while (moved < len)
          {
            //cout << "in loop temp val is " << temp_max->val << " and mover val is " << mover->val << " and moved is " << moved <<  endl;
            if (temp_max->val < mover->val)
             {
               temp_max = mover;
             }
            if (moved != len - 1)
              mover = mover->next;
            moved++;
          }
          //cout << "mover val is " << mover->val << endl;
          //cout << "temp max val is " << temp_max->val << endl;
          //cout << "len is " << len << endl << endl;
          len--;
          int temp = temp_max->val;
          temp_max->val = mover->val;
          mover->val = temp;
        }
        return head;
      }
  };

int main()
{
  Solution obj;
  ListNode input(1);
  ListNode a(2);
  input.next = &a;
  obj.insertionSortList(&input);
  cout << "head value is " << input.val << endl;
  cout << "head next value is " << input.next->val << endl;
  return 0;
}
