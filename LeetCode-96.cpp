#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <bitset>

using namespace std;

class Solution {
public:
    int linear(int a, vector<int>* memo)
    {
        cout << " a is " << a << " and memo a is " << (*memo)[a] << endl;
        if (a == 0)
            return 1;
        if (a == 1)
            return 1;
        if ((*memo)[a] != 0)
            return (*memo)[a];
        int ans = 0;
        for (int i = 1; i < a; i++)
            ans += linear(a-i,memo)*linear(i,memo);
        (*memo)[a] = ans;
        return (*memo)[a];
    }

    int numTrees(int n)
    {
        vector<int> memo (n+2);
        fill(memo.begin(), memo.end(), 0);
        memo[n+1] = linear(n+1 ,&memo);
        return memo[n+1];
    }
};

int main()
{
Solution obj;
int ans = obj.numTrees(4);
cout << "ans is " << ans << endl;
}
