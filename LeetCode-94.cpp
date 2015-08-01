#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
      stack<TreeNode*> st;
      vector<int> ans;
      if (root == NULL)
        return ans;
      st.push(root);
      while (st.empty() == 0)
      {
        cout << "St.top() is " << st.top()->val << endl;
        TreeNode* temp = st.top();
        if (st.top()->left != NULL)
        {
          st.push(st.top()->left);
          temp->left = NULL; // this destroys the tree. Can check if have visited this node before instead.
        }
        else
        {
          ans.push_back(st.top()->val);
          st.pop();
          if (temp->right != NULL)
            st.push(temp->right);
        }
      }
      return ans;
    }
};
