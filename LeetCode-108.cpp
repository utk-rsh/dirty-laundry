#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <sstream>

using namespace std;


class Solution {
public:
    TreeNode* recur(vector<int> &num, int low, int high, TreeNode* current)
    {
      if (low > high)
        return NULL;
      int mid = (low + high)/2;
      TreeNode* a = new TreeNode(num[mid]);
      a->left = recur(num, low, mid - 1, a);
      a->right = recur(num, mid + 1, high, a);
      return a;
    }

    TreeNode *sortedArrayToBST(vector<int> &num)
    {
      if (num.size() == 0)
        return 0;
      TreeNode *root = new TreeNode(num[num.size()/2]);
      root->left = recur(num, 0, (int)num.size()/2 - 1, root);
      root->right = recur(num, num.size()/2 + 1, num.size() - 1, root);
      return root;
    }
};
