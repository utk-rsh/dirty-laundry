#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
    int power(int a,int b)
    {
        if (b == 0)
            return 1;
        return a*power(a,b-1);
    }

    int titleToNumber(string s)
    {
        int ans = 0;
        int len = s.length() - 1;
        while (s.length() > 0)
        {
            string small = s.substr(0,1);
            s.erase(s.begin());
            ans += ((small[0] - 'A') + 1)*power(26,len);
            len--;
        }
        return ans;
    }
};
