#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0)
            return 0;
        vector<int> ans;
        if (n > 0)
            ans.push_back(A[0]);
        if (n > 1)
            ans.push_back(A[1]);
        if (n == 2)
        {
            return ans.size();
        }
        int rep = 1;
        if (A[0] == A[1])
            rep = 2;
        for (int i = 2; i < n; i++)
        {
            if (A[i] == A[i-1])
            {
                if (rep < 2)
                {
                    ans.push_back(A[i]);
                    rep++;
                }
            }
            else
            {
                ans.push_back(A[i]);
                rep = 1;
            }
        }
        copy(ans.begin(), ans.end(), A);
        return ans.size();
    }
};


int main()
{
int A[] = {1,1,1,2};
int n = 4;
Solution obj;
int b = obj.removeDuplicates(A,n);
cout << "ANSWER IS " << b << endl;
}
