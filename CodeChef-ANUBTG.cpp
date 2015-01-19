#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
int T;
cin >> T;
while (T > 0)
{
    T--;
    int N;
    cin >> N;
    vector<int> items;
    while (N > 0)
    {
        int temp;
        cin >> temp;
        items.push_back(temp);
        N--;
    }
    sort(items.begin(), items.end());
    int ans = 0;
    for (int i = items.size() - 1; i > -1; i--)
    {
        ans += items[i];
        if (i - 1 > -1)
            ans += items[i-1];
        i -= 3;
    }
    cout << ans << endl;
}
return 0;
}
