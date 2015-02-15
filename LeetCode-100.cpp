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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL)
        {
            if (q == NULL)
                return true;
            else
                return false;
        }
        if (q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        bool a = isSameTree(p->left, q->left);
        bool b = isSameTree(p->right, q->right);
        return a & b;
    }
};
