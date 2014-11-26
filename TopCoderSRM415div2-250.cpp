// TopCoder SRM 415 Div2 250

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class CollectingUsualPostmarks
{
public:
    int numberOfPostmarks(vector<int> prices, vector<int> have)
    {
        int money = 0;
        for (int i = 0; i < have.size(); i++)
        {
            money += prices[have[i]];
        }
        sort(prices.begin(), prices.end());
        int countt = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (money >= prices[i])
            {
                countt++;
                money = money - prices[i];
            }
            else
                break;
        }
        return countt;
    }
};
