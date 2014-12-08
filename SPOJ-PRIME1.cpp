#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
int T;
cin >> T;
while (T > 0)
{
    T--;
    long m,n;
    cin >> m >> n;
 //   cout << "m and n are " << m << " " << n << endl;
    for (long i = m; i <= n; i++)
    {
        if (i == 1)
            continue;
        float limit = sqrt(i);
     //   cout << "int conversion done" << limit << endl;
        long l = long (ceil(limit));
   //     cout << "l is " << l << " and i is " << i << endl;
        int check = 1;
        for (long  j = 2LL; j <= l; j++)
        {
     //       cout << "i mod j is " << i % j << endl;
            if (i == 2)
                break;
            if (i%j == 0)
            {
                check  = 0;
                break;
            }
        }
        if (check == 1)
            cout << i << endl;
    }
}
}
