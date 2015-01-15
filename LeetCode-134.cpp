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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int sum = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0)
            {
                sum = 0;
                index = i+1;
            }
        }
        if (total < 0)
            return -1;
        else
            return index;
    }
};
