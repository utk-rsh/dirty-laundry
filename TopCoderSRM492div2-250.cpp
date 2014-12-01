
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class TimeTravellingCellar
{
public:
    int determineProfit(vector<int> profit, vector<int> decay)
    {
        int maxx1 = 0;
        int maxx2 = 0;
        int maxi = 0;
        for (int i = 0; i < profit.size(); i++)
        {
            if (profit[i] > maxx1)
                {
                    maxx2 = maxx1;
                    maxx1 = profit[i];
                    maxi = i;
                }
            else if (profit[i] > maxx2)
                maxx2 = profit[i];
        }
        int minn1 = 10000;
        int minn2 = 10000;
        int mini = 0;
        for (int i = 0; i < decay.size(); i++)
        {
            if (decay[i] < minn1)
            {
                minn2 = minn1;
                minn1 = decay[i];
                mini = i;
            }
            else if (decay[i] < minn2)
                minn2 = decay[i];
        }
        cout << "maxx1 " << maxx1 << endl;
        cout << "maxx2 " << maxx2 << endl;
        cout << "maxi " << maxi << endl;
        cout << "minn1 " << minn1 << endl;
        cout << "minn2 " << minn2 << endl;
        cout << "mini " << mini << endl;
        if (maxi != mini)
            return maxx1 - maxx2;
        else
            return max(maxx1 - minn2, maxx2 - minn1);
    }
};
