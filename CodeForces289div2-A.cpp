#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

#define INT_MAX 2147483647
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    vector<vector<int> > ans;
    vector<int> temp;
    for (int i = 0; i < n; i++)
        temp.push_back(1);
    for (int i = 0; i < n; i++)
        ans.push_back(temp);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            ans[i][j] = ans[i-1][j] + ans[i][j-1];
        }
    }
    cout << ans[n-1][n-1] << endl;
    return 0;
}
