#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class PairingPawns
{
public:
    int savedPawnCount(vector<int> start)
    {
        for (int i = start.size() - 1; i > 0; i--)
        {
            start[i-1] += start[i]/2;
        }
        return start[0];

    }

};
