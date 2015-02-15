#include <iostream>
#include <vector>
#include <string>
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
    void recur(TreeNode *top, int current, int* total)
    {
        if (top == NULL)
            return;
        current = current*10 + top->val;
        if ((top->left == NULL) && (top->right == NULL))
        {
            *total += current;
        }
        else
        {
            recur(top->left, current, total);
            recur(top->right, current, total);
        }
        return;
    }


    int sumNumbers(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = 0;
        recur(root, 0, &ans);
        return ans;
    }
};
