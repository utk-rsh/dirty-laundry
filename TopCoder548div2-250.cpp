#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class KingdomAndDucks
{
public:
int minDucks(vector<int> duckTypes)
{
    int arr[51] = {0};
    for (int i = 0; i < duckTypes.size(); i++)
    {
        arr[duckTypes[i]]++;
    }
    int maxx = 0;
    int c = 0;
    for (int i = 0; i < 51; i++)
    {
        if (arr[i] != 0)
            c++;
        maxx = max(maxx, arr[i]);

    }
    return maxx*c;
}

};
