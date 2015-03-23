#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
      if (prices.size() == 0)
        return 0;
      vector<int> rl;
      rl.reserve(prices.size());
      int low = prices[0];
      int high = prices[0];
      int profit = 0;
      for (int i = 0; i < prices.size(); i++)
      {
        low = min(low, prices[i]);
        profit = prices[i] - low;
        if (rl.size() > 0)
          profit = max(profit, rl[rl.size() - 1]);
        rl.push_back(profit);
      }
      high = prices[prices.size() - 1];
      vector<int> lr;
      lr.reserve(rl.size());
      profit = 0;
      for (int i = prices.size() - 1; i > -1; i--)
      {
        high = max(high, prices[i]);
        profit = high - prices[i];
        if (lr.size() > 0)
          profit = max(profit, lr[lr.size() - 1]);
        lr.push_back(profit);
      }
      profit = rl[0] + lr[0];
      for (int i = 0; i < rl.size(); i++)
      {
        //cout << "i: " << i << "  rl[i]: " << rl[i] << "  lr[i]: " << lr[i] << endl;
        profit = max(profit, rl[i] + lr[lr.size() - 1 - i]);
      }
      return profit;
    }
};
