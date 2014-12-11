#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class TrianglesContainOriginEasy
{
public:
float sign (int p1x, int p1y, int p2x, int p2y, int p3x, int p3y)
{
    return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

bool PointInTriangle (int v1x, int v1y, int v2x, int v2y, int v3x, int v3y)
{
    bool b1, b2, b3;

    b1 = sign(0,0, v1x, v1y, v2x, v2y) < 0;
    b2 = sign(0,0, v2x, v2y, v3x, v3y) < 0;
    b3 = sign(0,0, v3x, v3y, v1x, v1y) < 0;

    return ((b1 == b2) && (b2 == b3));
}

int count(vector<int> x, vector<int> y)
{
    int ans = 0;
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = i+1; j < x.size(); j++)
        {
            for (int k = j+1; k < x.size(); k++)
            {
                ans += PointInTriangle(x[i], y[i], x[j], y[j], x[k], y[k]);
            }
        }
    }
    return ans;
}
};
