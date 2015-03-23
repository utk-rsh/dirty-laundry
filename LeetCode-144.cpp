#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
      stack<TreeNode*> st;
      vector<int> ans;
      if (root == NULL)
        return ans;
      st.push(root);
      while (st.empty() == 0)
      {
        TreeNode* current = st.top();
        if ((current->val != -79284) && (current->val != -79285))
          ans.push_back(current->val);
        if ((current->left != NULL) && (current->val != -79284) && (current->val != -79285))
        {
            st.push(current->left);
            current->val = -79284;
        }
        else
        {
          if ((current->right != NULL) && (current->val != -79285))
          {
            st.push(current->right);
            current->val = -79285;
          }
          else
          {
            st.pop();
          }
        }
      }
      return ans;
    }
};
