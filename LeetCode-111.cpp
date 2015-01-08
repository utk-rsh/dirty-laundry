#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int helper(TreeNode* current, int depth)
    {
        if (current == NULL)
            return depth;
        depth++;
        if (current->left == NULL)
            depth = helper(current->right, depth);
        else if (current->right == NULL)
            depth = helper(current->left, depth);
        else
            depth = min(helper(current->left, depth), helper(current->right, depth));
        return depth;
    }

    int minDepth(TreeNode *root)
    {
        return helper(root, 0);
    }
};
