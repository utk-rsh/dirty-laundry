#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class ConnectingCars
{
public:
long long minimizeCost(vector<int> positions, vector<int> lengths)
{
    vector<pair<int, int> > all;
    for (int i = 0; i  < positions.size(); i++)
            all.push_back(make_pair(positions[i], lengths[i]));
    sort(all.begin(), all.end());
    int mid = all.size()/2;
    long long ans = 0;
    long long cushion = 0;
    for (int i = mid - 1; i >= 0; i--)
    {
        ans += all[mid].first - all[i].first - all[i].second - cushion;
        cushion += all[i].second;
    }
    cushion = 0;
    for (int i = mid + 1; i < all.size(); i++)
    {
        ans += all[i].first - all[mid].first - all[mid].second - cushion;
        cushion += all[i].second;
    }
    return ans;
}
};
