#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
      int ans = -1;
      int counter = 1;
      inorder(root, counter, k, ans);
      return ans;
    }

    void inorder(TreeNode* current, int &counter, int k, int &ans)
    {
      if (current == NULL || counter > k)
        return;
      inorder(current->left, counter, k, ans);
      if (counter > k)
        return;
      if (counter == k)
      {
        ans = current->val;
        counter++;
        return;
      }
      counter++;
      inorder(current->right, counter, k, ans);
      return;
    }
};

int main()
{
  TreeNode a(2);
  TreeNode b(1);
  a.left = &b;
  Solution obj;
  int returned = obj.kthSmallest(&a, 1);
  cout << "returned is " << returned << endl;
  return 0;
}
