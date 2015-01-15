#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>


using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num)
    {
        if (num.size() == 1)
            return 0;
        if (num[0] > num[1])
            return 0;
      //  if (num.size() == 2)
        //    return 2;
        if (num[num.size() -1] > num[num.size() - 2])
            return num.size()-1;
        for (int i = 1; i < num.size() - 1; i++)
        {
            if ((num[i] > num[i-1]) && (num[i] > num[i+1]))
                return i;
        }
    }
};
