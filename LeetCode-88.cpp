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
    void merge(int A[], int m, int B[], int n)
    {
        int C[m+n] = {-1};
        if (m == 0)
        {
            copy(B,B+n,A);
            return;
        }
        if (n == 0)
            return;
        int i = 0;
        int j = 0;
        int counter = 0;
        while ((i < m) && (j < n))
        {
            if (A[i] < B[j])
            {
                C[counter] = A[i];
                i++;
                counter++;
            }
            else
            {
                C[counter] = B[j];
                j++;
                counter++;
            }
        }
        if (i == m)
        {
            while (j < n)
            {
                C[counter] = B[j];
                j++;
                counter++;
            }
        }
        if (j == n)
        {
            while (i < m)
            {
                C[counter] = A[i];
                i++;
                counter++;
            }
        }
        copy(C, C+m+n, A);
        return;
    }
};
