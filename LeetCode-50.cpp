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
    double pow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == -2147483648)
            return (1/x)*(1/x)*pow(1/x, -(n+2));
        if (n < 0)
            return pow(1/x, -n);
        if (n == 1)
            return x;
        if (n%2 == 1)
            return x*pow(x,n-1);
        else
            return pow(x*x,n/2);
    }
};
