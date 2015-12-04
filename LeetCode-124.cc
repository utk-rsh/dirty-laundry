/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  int maxPathSum(TreeNode* root) 
  {
    int ans = -2147483648;
    recur(root, &ans);
    return ans;
  }

  int recur(TreeNode* current, int* ans)
  {
    if (current == NULL)
      return 0;
    int left = recur(current->left, ans);
    int right = recur(current->right, ans);
    int temp = max(left + current->val, left + right + current->val);
    temp = max(temp, right + current->val);
    temp = max(temp, current->val);
    *ans = max(*ans, temp);
    return (max((max(left, right) + current->val),current->val));
  }
};


