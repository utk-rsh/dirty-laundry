#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class EllysCandyGame
{
public:
int out(vector<int> sw, int d)
{
    int first = 0;
    int ans = d;
    for (int i = 0; i < sw.size(); i++)
    {
        if (sw[i] == 0)
            continue;
        else
        {
            int temp = sw[i];
            if ( i < sw.size()-1)
                sw[i+1] *= 2;
            if ( i > 0)
                sw[i-1] *= 2;
            sw[i] = 0;
            if (first == 0)
            {
                first++;
                ans = -out(sw, -(d+temp));
            }
            else
                ans = max(ans, -out(sw, -(d+temp)));
            sw[i] = temp;
            if ( i < sw.size()-1)
                sw[i+1] = sw[i+1]/2;
            if ( i > 0)
                sw[i-1] = sw[i-1]/2;
        }
    }
    return d;
}

string getWinner(vector<int> sweets)
{
    int d = out(sweets, 0);
    cout << "returned diff is " << d << endl;
    if (d > 0)
        return "Elly";
    else if (d == 0)
        return "Draw";
    else
        return "Kris";
}
};
