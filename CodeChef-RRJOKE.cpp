#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>

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
    for (int i = 0; i < N; i++)
    {
        int a,b;
        cin  >> a >> b;
    }
    int ans = 1;
    for (int i = 2; i <= N; i++)
        ans = ans^i;
    cout << ans << endl;
}
return 0;
}
