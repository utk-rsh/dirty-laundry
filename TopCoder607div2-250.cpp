#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class BoundingBox
{
public:
int smallestArea(vector<int> x, vector<int> y)
{
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int a = x[x.size() -1] - x[0];
    int b = y[y.size() - 1] - y[0];
    return a*b;
}
};
