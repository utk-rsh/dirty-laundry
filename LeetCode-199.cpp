#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void recur(TreeNode *current, vector<int> &ans, int c, int *m)
    {
      if (current == NULL)
        return;
      if (c == *m)
      {
        ans.push_back(current->val);
        *m = *m + 1;
      }
      recur(current->right, ans, c+1, m);
      recur(current->left, ans, c+1, m);
      return;
    }

    vector<int> rightSideView(TreeNode *root)
    {
      vector<int> ans;
      int m = 1;
      recur(root, ans, 1, &m);
      return ans;
    }
};
