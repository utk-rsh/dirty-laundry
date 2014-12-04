#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class CatchTheBeatEasy
{
public:
string ableToCatchAll(vector<int> x, vector<int> y)
{
    x.insert(x.begin(), 0);
    y.insert(y.begin(), 0);
    for (int i = 1; i < x.size(); i++)
    {
        if (abs(x[i]- x[i-1]) > abs(y[i] - y[i-1]))
            return "Not able to catch";
    }
    return "Able to catch";

}

};
