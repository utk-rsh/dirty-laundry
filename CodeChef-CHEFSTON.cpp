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
    int N, K;
    cin >> N >> K;
    vector<long long> time;
    vector<long long> profit;
    while (N > 0)
    {
        N--;
        long long temp;
        cin >> temp;
        time.push_back(temp);
    }
    N = time.size();
    while (N > 0)
    {
        N--;
        long long temp;
        cin >> temp;
        profit.push_back(temp);
    }
    long long maxp = 0;
    for (int i = 0; i < profit.size(); i++)
    {
        maxp = max(maxp, (K/time[i])*profit[i]);
    }
    cout << maxp << endl;
}
}
