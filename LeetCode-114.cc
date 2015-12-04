/**
 * Definition for a binary tree node.
 * struct TreeNode {
a *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void postorder(TreeNode* current, TreeNode **last)
  {
    if (current == NULL)
      return;
    TreeNode* rtemp = current->right;
    TreeNode* ltemp = current->left;
    current->right = NULL;
    current->left = NULL;
    if ((*last) != current)
    {
      (*last)->right = current;
      (*last) = (*last)->right;
    }
    postorder(ltemp, last);
    postorder(rtemp, last);
    return;
  }


void flatten(TreeNode* root) 
  {
    postorder(root, &root);
    return;     
  }
};
