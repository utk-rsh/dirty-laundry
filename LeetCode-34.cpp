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
    vector<int> searchRange(int A[], int n, int target)
    {
        auto a = lower_bound(A, A+n, target);
        auto b = upper_bound(A, A+n, target);
        int one = a - A;
        int two = b - A - 1;
        if (A[one] != target)
        {
            one = -1;
            two = -1;
        }
        vector<int> ans;
        ans.push_back(one);
        ans.push_back(two);
        return ans;
    }
};

int main()
{
int A[] = {5,7,7,8,8,10};
int n = 6;
Solution obj;
vector<int> ans = obj.searchRange(A,n,4);
cout << "Result is " << ans[0] << " " << ans[1] << endl;
return 0;
}
