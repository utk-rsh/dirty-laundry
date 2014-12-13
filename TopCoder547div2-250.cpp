#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class MinimalTriangle
{
public:
double maximalArea(int length)
{
    double a = sqrt(3);
    double b = length*1.0*length;
    return b*a/4.0;
}
};
