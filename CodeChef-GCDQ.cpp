#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>

using namespace std;

int gcd(int a, int b)
{
    if (b > a)
        return gcd(b,a);
    else if (b == 0)
        return a;
    else
        return gcd(a%b, b);
}

int main()
{
int T;
scanf("%d", &T);
while (T > 0)
{
    T--;
    int N, Q;
    scanf("%d", &N);
    scanf("%d", &Q);
    int* all = new int[N];
    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        all[i] = temp;
    }
    int* left = new int[N];
    memset(left, -1, sizeof(int)*N);
    int* right = new int[N];
    memset(right, -1, sizeof(int)*N);
    for (int i = 0; i < Q; i++)
    {
        int L, R;
        scanf("%d", &L);
        scanf("%d", &R);
        int le = -1;
        int ri = -1;
        int temp = all[0];
        if (L > 1)
            le = left[L-1-1];
        if (R < N)
            ri = right[R];
        temp = all[0];
        if (le == -1)
        {
            int j = 0;
            for (j = 0; j < L - 1; j++)
            {
                if (left[j] == -1)
                    break;
            }
            if (j != 0) temp = left[j-1];
            for (int i = j; i < L - 1; i++)
            {
                temp = gcd(temp, all[i]);
                left[i] = temp;
            }
            le = temp;
        }
 /*       cout << "le is" << le << endl;
        cout << "left array is ";
        for (int i = 0; i < N; i++)
            cout << left[i] << " ";
        cout << endl;
   */     temp = all[N-1];
        if (ri == -1)
        {
            int j = 0;
            for (j = N-1; j > R - 1; j--)
            {
                if (right[j] == -1)
                    break;
            }
            if (j != N-1) temp = right[j+1];
            for (int i = j; i > R - 1; i--)
            {
                temp = gcd(temp, all[i]);
                right[i] = temp;
            }
            ri = temp;
        }
  /*      cout << "ri is" << le << endl;
        cout << "right array is ";
        for (int i = 0; i < N; i++)
            cout << right[i] << " ";
        cout << endl;
    */    int ans;
        if ((L != 1) && (R != N))
            ans = gcd(le,ri);
        else if (R == N)
            ans = le;
        else
            ans = ri;
        printf("%d\n",ans);
    }
}
}

