#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int ma = -1;
        int diff = 0;
        if (prices.size() < 2)
                return diff;
        for (int i = (int)prices.size() - 1; i > -1; i--)
        {
            ma = max(ma, prices[i]);
            diff = max(diff, ma - prices[i]);
        }
        return diff;
    }
};
