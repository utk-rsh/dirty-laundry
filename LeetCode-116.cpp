#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>


using namespace std;

/*
  struct TreeLinkNode {
    int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };*/

class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        queue<TreeLinkNode* > q;
        q.push(root);
        q.push(NULL);
        while (q.empty() == 0)
        {
            TreeLinkNode* temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if (q.empty() == 1)
                    break;
                if (q.front() == NULL)
                    break;
                q.push(NULL);
                continue;
            }
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            temp->next = q.front();
        }
        return;
    }
};
