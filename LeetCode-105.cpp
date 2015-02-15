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
    void print(TreeNode* root)
    {
        TreeNode* dummy = new TreeNode (-10);
        queue<TreeNode*> q;
        q.push(root);
        q.push(dummy);
        while (q.empty() != 1)
        {
            if (q.size() == 1)
                if (q.front() == dummy)
                    return;
            TreeNode* f = q.front();
            q.pop();
            if (f == NULL)
                continue;
            if (f == dummy)
            {
                q.push(f);
                cout << endl;
                continue;
            }
            cout << f->val << " ";
            q.push(f->left);
            q.push(f->right);
        }
        return;
    }

    void recurl(vector<int>* preorder, vector<int>* inorder, int *prei, int low, int high, TreeNode* top)
    {
 //       cout << "recur L called for " << top->val << " with prei as " << *prei << " low and high as " << low << high << endl;
        if (low > high)
        {
            --(*prei);
 //           cout << "returning because " << low << " > " << high << endl << endl;
            return;
        }
        if (low == high)
        {
 //           cout << "left kid will be " << inorder[low] << endl << endl;
            TreeNode *kid = new TreeNode ((*inorder)[low]);
            top->left = kid;
            return;
        }
        for (int i = low; i <= high; i++)
        {
            if ((*inorder)[i] == (*preorder)[*prei])
            {
 //               cout << "left kid will be " << inorder[i] << endl << endl;
                TreeNode *kid = new TreeNode ((*inorder)[i]);
                top->left = kid;
 //               cout << "increasing prei ";
                ++(*prei);
                recurl(preorder, inorder, prei, low, i-1, top->left);
 //                cout << "increasing prei ";
                ++(*prei);
                recurr(preorder, inorder, prei, i+1, high, top->left);
                return;
            }
        }
 //       cout << "LEFT FLAG NOT SET TO ZERO. CHECK" << endl;
        return;
    }

    void recurr(vector<int>* preorder, vector<int>* inorder, int* prei, int low, int high, TreeNode* top)
    {
//       cout << "recur R called for " << top->val << " with prei as " << *prei << " low and high as " << low << high << endl;
        if (low > high)
        {
            --(*prei);
            return;
        }
        if (low == high)
        {
//            cout << "right kid will be " << inorder[low] << endl << endl;
            TreeNode *kid = new TreeNode ((*inorder)[low]);
            top->right = kid;
            return;
        }
        for (int i = low; i <= high; i++)
        {
            if ((*inorder)[i] == (*preorder)[*prei])
            {
//                cout << "right kid will be " << inorder[i] << endl << endl;
                TreeNode *kid = new TreeNode ((*inorder)[i]);
                top->right = kid;
//                cout << "increasing prei ";
                ++(*prei);
                recurl(preorder, inorder, prei, low, i-1, top->right);
//                cout << "increasing prei ";
                ++(*prei);
                recurr(preorder, inorder, prei, i+1, high, top->right);
                return;
            }
        }
//        cout << "RIGHT FLAG NOT SET. CHECK" << endl;
        return;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int prei = 1;
        if (preorder.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 0; i < preorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
            {
//                cout << "main inorder preorder match at " << i << endl;
                recurl(&preorder, &inorder, &prei, 0, i-1, root);
                ++prei;
                recurr(&preorder, &inorder, &prei, i+1, (int)preorder.size() - 1, root);
//                cout << "Successfully returning" << endl;
                return root;
            }
        }
    }
};

int main()
{
    vector<int> pre;
    pre.push_back(6);
    pre.push_back(2);
    pre.push_back(1);
    pre.push_back(4);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(7);
    pre.push_back(9);
    pre.push_back(8);
    pre.push_back(10);
    pre.push_back(11);
    pre.push_back(12);
    vector<int> in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    in.push_back(4);
    in.push_back(5);
    in.push_back(6);
    in.push_back(7);
    in.push_back(11);
    in.push_back(10);
    in.push_back(12);
    in.push_back(8);
    in.push_back(9);
    Solution obj;
    TreeNode* ans = obj.buildTree(pre, in);
    cout << "Printing" << endl;
    obj.print(ans);
    return 0;
}
