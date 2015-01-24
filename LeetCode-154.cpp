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
    int findMin(vector<int> &prices)
    {
        int low = 0;
        int high = prices.size() - 1;
        if (prices[high] > prices[low])
            return prices[low];
        while (high - low > 1)
        {
            int mid = (low+high)/2;
           // cout << "low is " << low << " mid is " << mid << " and high is " << high << endl;
          //  cout << "plow is " << prices[low] << " pmid is " << prices[mid] << " and phigh is " << prices[high] << endl << endl;
            if (prices[low] < prices[high])
                return prices[low];
            else if (prices[mid] == prices[low])
                low++;
            else if (prices[mid]== prices[high])
                high--;
            else if (prices[mid] > prices[low])
            {
                low = mid;
            }
            else if (prices[mid] < prices[low])
            {
                high = mid;
            }
        }
    //    cout << "final low and high are  " << low << " " << high << endl;
        return min(prices[low], prices[high]);
    }
};

int main()
{
vector<int> test;
test.push_back(10);
test.push_back(1);
test.push_back(10);
test.push_back(10);
test.push_back(10);
Solution obj;
int ans = obj.findMin(test);
cout << "ans is " << ans << endl;
return 0;
}
