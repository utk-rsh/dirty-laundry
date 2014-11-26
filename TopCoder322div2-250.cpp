// TopCoder SRM 322 Div2 250
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class DerivativeSequence
{
public:

    vector<int> derSeq(vector<int> a, int n)
    {
        while (n > 0)
        {
            vector<int> ans;
            for (int i = 1; i < a.size(); i++)
            {
                ans.push_back(a[i] - a[i-1]);
            }
            a = ans;
            n--;
        }
        return a;

    }
};
