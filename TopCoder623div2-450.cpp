#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
# define PI           3.141592653589793238
using namespace std;

class CatAndRat
{
public:
double getTime (int R, int T, int Vrat, int Vcat)
{
    double dist;
    if (Vrat >= Vcat)
        return -1.0;
    if (T >= PI*R/Vrat)
        dist = PI*R;
    else
        dist = Vrat*T;
    double time;
    time = dist/(Vcat - Vrat);
    return time;

}
};
