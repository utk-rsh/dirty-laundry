#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool recurse(TreeNode *root, long long low, long long high)
    {
      if (root == nullptr)
        return true;
      if (root->left != nullptr)
      {
        if (root->left->val >= root->val)
          return false;
        if (root->left->val <= low)
          return false;
      }
      if (root->right != nullptr)
      {
        if (root->right->val >= high)
          return false;
        if (root->right->val <= root->val)
          return false;
      }
      return (recurse(root->left, low, root->val) && recurse(root->right, root->val, high));
    }

    bool isValidBST(TreeNode *root)
    {
      return recurse(root, -10000000000000, 100000000000);
    }
};
