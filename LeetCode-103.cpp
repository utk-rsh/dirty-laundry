#include <iostream>
#include <vector>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
      vector<vector<int> > ans;
      if (root == NULL)
        return ans;
      queue<TreeNode*> q;
      q.push(root);
      TreeNode dummy(-79284);
      q.push(&dummy);
      vector<int> temp;
      int side = 0;
      while (q.empty() == 0)
      {
        TreeNode *element = q.front();
        if (element == &dummy)
        {
          q.push(element);
          ans.push_back(temp);
          temp.clear();
          side = (side + 1) % 2;
        }
        else
        {
          if (element->left != NULL)
              q.push(element->left);
            if (element->right != NULL)
              q.push(element->right);
          if (side == 0)
            temp.push_back(element->val);
          if (side == 1)
            temp.insert(temp.begin(), element->val);
        }
        q.pop();
        if (q.size() == 1)
        {
          ans.push_back(temp);
          break;
        }
      }
      return ans;
    }
};

int main()
{
  TreeNode root(1);
  TreeNode a1(2);
  TreeNode a2(3);
  TreeNode b1(4);
  TreeNode b2(5);
  root.left = &a1;
  root.right = &a2;
  a1.left = &b1;
  a1.right = &b2;
  Solution obj;
  vector<vector<int> > ans = obj.zigzagLevelOrder(&root);
  cout << "size of ans is " << ans.size() << endl;
  cout << ans[2][0] << endl;
  return 0;
}
