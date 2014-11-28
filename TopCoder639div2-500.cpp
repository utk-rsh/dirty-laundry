#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class AliceGameEasy
{
public:

long long binarys(long long target, long long low, long long high)
{
    long long mid = (low)/2 + (high)/2;
    if ((low%2 == 1) && (high%2 == 1))
        mid++;
    if (pro(low) == target)
        return low;
    if (pro(high) == target)
        return high;
    if ((high == low) || (high == low + 1))
    {
        return -1;
    }
    else if (pro(mid) > target)
        return binarys(target, low, mid);
    else if (pro(mid) == target)
        return mid;
    else
        return binarys(target, mid, high);
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

long long findMinimumValue(long long x, long long y)
{
    if (x + y == 0)
        return 0;
    long long n = binarys(x+y, 0, 2000000);
    cout << "n from binary search was " << n << endl;
    if (n == -1)
        return -1;
    return binaryt(x, 0, n, n);

}
};


int main()
{
AliceGameEasy obj;
long long a = 932599670050;
long long b = 67400241741;
long long c = 20000000000000;
cout << "Arithmetic is " << c-b-a << endl;
cout << obj.findMinimumValue(a,b);
return 0;
}

