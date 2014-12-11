#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class BuyingTshirts
{
public:
int meet(int T, vector<int> q, vector<int> p)
{
    int qt = 0;
    int pt = 0;
    int ans = 0;
    for (int i = 0; i < q.size(); i++)
    {
        qt += q[i];
        pt += p[i];
        if ((qt >= T) && (pt >= T))
            ans++;
        qt = qt%T;
        pt = pt%T;
    }
    return ans;
}
};
