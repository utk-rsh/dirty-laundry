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
    void sortColors(int A[], int n)
    {
        int ai = 0;
        int ci = n-1;
        int bi = 0;
        if (n == 1)
            return;
        while (bi <= ci)
        {
            if (A[bi] == 0)
            {
                if (ai == bi)
                {
                    bi++;
                    continue;
                }
                swap(A[ai],A[bi]);
                ++ai;
                --bi;
            }
            if (A[bi] == 2)
            {
                if (bi == ci)
                {
                    bi++;
                    continue;
                }
                swap(A[ci],A[bi]);
                --ci;
                --bi;
            }
            if (ai > ci)
                return;
            bi++;
        }
        return;
    }
};

int main()
{
int A[] = {2,0,1};
Solution obj;
obj.sortColors(A,3);
cout << A[0] << " " << A[1] << " " << A[2] << endl;
return 0;
}
