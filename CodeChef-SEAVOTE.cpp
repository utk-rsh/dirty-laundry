//http://www.codechef.com/JAN15/problems/SEAVOTE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
int T;
cin >> T;
while (T > 0)
{
    T--;
    int lowsum = 0;
    int highsum = 0;
    int N;
    cin >> N;
    while (N > 0)
    {
        N--;
        int temp;
        cin >> temp;
        highsum += temp;
        if (temp > 0)
            lowsum = lowsum + temp - 1;
    }
    if ((highsum >= 100) && (lowsum < 100))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
}
