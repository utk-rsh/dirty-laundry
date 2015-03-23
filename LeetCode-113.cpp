#include <iostream>
#include <cmath>
#include <string>
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
    void recur(vector<vector<int> > *ans, TreeNode *current, int target, vector<int> *path)
    {
      if (current == NULL)
        return;
      path->push_back(current->val);
      target = target - current->val;
      if (target == 0)
      {
        if ((current->left == NULL) && (current->right == NULL))
          ans->push_back(*path);
      }
      recur(ans, current->left, target, path);
      recur(ans, current->right, target, path);
      path->pop_back();
      return;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
      vector<vector<int> >ans;
      vector<int> path;
      recur(&ans, root, sum, &path);
      return ans;
    }
};

int main()
{
  TreeNode single(1);
  Solution obj;
  vector<vector<int> > ans = obj.pathSum(&single, 1);
  cout << "The size of returned ans is " << ans.size() << endl;
  cout << "The first element is " << ans[0][0] << endl;
  return 0;
}
