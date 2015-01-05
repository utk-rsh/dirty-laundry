#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans^A[i];
        }
        return ans;
    }
};
