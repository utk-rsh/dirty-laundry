#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class KingdomAndTrees
{
public:
bool solveFor(vector<int> temp, int x)
{
    for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] < temp[i-1])
                temp[i] = min(temp[i]+x, temp[i-1]+1);
            else
                temp[i] = max(temp[i] - x, temp[i-1]+1);
        }
    bool valid = 1;
    for (int i = 0; i < temp.size() - 1; i++)
        if (temp[i] >= temp[i+1])
            valid = 0;
    return valid;
}
int se(vector<int> height, int low, int high)
{
    if (low == high)
        return low;
    int x = (low + high)/2;
    vector<int> temp = height;
    cout << "temp before is ";
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";
    cout << endl;
    bool valid = solveFor(temp, x);
    if (high - low == 1)
    {
        if (solveFor(temp, low) != solveFor(temp, high))
            return high;
        else
            return low;
    }
    cout << "checking for x equal to " << x << " and valid is " << valid << endl;
    cout << "high and low were " << high << "  " << low << endl;
    cout << "temp after is ";
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";
    cout << endl << endl;
    if (valid == 1)
        return se(height, low, x);
    else
        return se(height, x, high);
}

int minLevel(vector<int> heights)
{
    heights.insert(heights.begin(),0);
    return se(heights, 0, 1000000001);
}

};
