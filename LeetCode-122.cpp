#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int bought = -1;
        int profit = 0;
        if (prices.size() < 2)
            return 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i+1])
            {
                if (bought == -1)
                    bought = prices[i];
            }
            if (prices[i] > prices[i+1])
            {
                if (bought != -1)
                {
                    profit += prices[i] - bought;
                    bought = -1;
                }
            }
        }
        if (bought != -1)
            profit += prices[prices.size() - 1] - bought;
        return profit;
    }
};
