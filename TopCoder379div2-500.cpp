#include<iostream>
#include<vector>

using namespace std;

class SellingProducts
{
public:
    int optimalPrice(vector<int> price, vector<int> cost)
    {
        int maxx = 0;
        int price_optimal = 0;
        for (int i = 0; i < price.size(); i++)
            if (price[i] > maxx)
                maxx = price[i];
        int p = 0;
        for (int i = 0; i < price.size(); i++)
        {
            int sp = price[i];
            int mp = 0;
            for (int k = 0; k < price.size(); k++)
            {
                if (sp <= price[k])
                {
                    if (sp - cost[k] > 0)
                    {
                        cout << "adding to mp with price as " << price[k] << endl;
                        mp += sp - cost[k];
                    }
                }
            }
            cout << "mp is " << mp << " at a selling price of " << sp << endl;
            if (mp > p)
            {
                p = mp;
                price_optimal = sp;
            }
        }
        cout << "returning value " << price_optimal << endl;
        return price_optimal;
    }
};
