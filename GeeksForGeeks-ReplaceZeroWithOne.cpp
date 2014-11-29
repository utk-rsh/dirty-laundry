#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class AliceGameEasy
{
public:
long long findMinimumValue(long long x, long long y)
{
    double a = x;
    double b = y;
    double n = (-1 + sqrt(1+8*(x+y)))/2;
    cout << "n is " << n << endl;
    int ans = round(n);
    cout << "ans is " << ans << endl;
    if (pro(ans) != x+y)
        return -1;
 //   return lineart(x, ans);
   return binaryt(x, 0, ans, ans);
}

long long diff(long long up, long long low)
{
    if ((up - low) % 2 == 0)
        return ((up - low)/2)*(up+low+1);
    else
        return (up-low)*((up+low+1)/2);
}


long long pro(long long a)
{
    if (a%2 == 0)
        return ((a/2))*(a+1);
    else
        return ((a+1)/2)*a;
}

long long lineart(long long target, long long maxx)
{
    int acc = 0;
    int c = 0;
    while (true)
    {
        if (acc >= target)
            return c;
        acc += maxx;
        maxx--;
        c++;
    }
}

long long binaryt(long long target, long long low, long long high, long long maxx)
{
    if (high - low == 1)
        return maxx - low;
    long long mid = (low)/2 + (high)/2;
    if ((low%2 == 1) && (high%2 == 1))
        mid++;
    if (diff(maxx, mid) > target)
        return binaryt(target, mid, high, maxx);
    else if (diff(maxx, mid) == target)
        return maxx - mid;
    else
        return binaryt(target, low, mid, maxx);
}

};


int main()
{
AliceGameEasy obj;
long long a = 932599670050;
long long b = 67400241741;
long long c = 20000000000000;
cout << "Arithmetic is " << c-b-a << endl;
cout << obj.findMinimumValue(11,10);
return 0;
}

