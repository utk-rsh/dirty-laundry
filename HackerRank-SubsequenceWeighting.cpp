#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

long maxWeight(pair<long, long>* arr, long* memo, int n)
{
    if (memo[n] != 0)
        return memo[n];
    long tw = arr[n].second;
    for (int i = 0; i < n; i++)
        if (arr[i].first < arr[n].first)
            tw = max(tw, arr[n].second + maxWeight(arr, memo, i));
    memo[n] = tw;
    return tw;
}

int main()
{
int T;
cin >> T;
while (T > 0)
{
    T--;
    int n;
    cin >> n;
    pair<long, long>* arr = new pair<long, long>[n];
    long* memo = new long[n];
    memset(memo, 0LL, sizeof(memo));
    for (int i = 0; i < n; i++)
    {
        long temp;
        cin >> temp;
        arr[i].first = temp;
    }
    for (int i = 0; i < n; i++)
    {
        long temp;
        cin >> temp;
        arr[i].second = temp;
    }
    long answer = 0;
    for (int i = 0; i < n; i++)
        answer = max(answer, maxWeight(arr, memo, i));
    cout << answer << endl;

}
return 0;
}
