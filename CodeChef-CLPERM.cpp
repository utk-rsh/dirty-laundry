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
    scanf("%d", &T);
    while (T > 0)
    {
        T--;
        long long N;
        int K;
        scanf("%d",&N);
        scanf("%d",&K);
        long long negativesum = 0;
        long long temp;
        int count = 0;
        int broken = 0;
        long long sum;
        int* missing = new int[K];
        if (K == 0)
            goto skipped;

        for (int i = 0; i < K; i++)
        {
            scanf("%d", &temp);
            missing[i] = temp;
        }
        sort(missing, &missing[K-1]+1);
     //   for (int i = 0 ; i < K; i++)
     //       cout << missing[i] << "  ";
     //   cout << endl;
        for (int i = 0; i < K; i++)
        {
            temp = missing[i];
            sum = ((temp - 1)*(temp))/2;
            negativesum += missing[i];
            if (sum - negativesum < 0)
            {
                broken = 1;
                break;
            }
        }
        if (broken == 1)
        {
      //      cout << "Broke early. Temp is " << temp << endl;
            if (temp%2 == 0)
                count = 2;
            else
                count = 1;
        }

        skipped:
        if (broken == 0)
        {
            sum = ((N)*(N+1))/2;
     //       cout << "sum before N is increasing is " << sum << endl;
            for (int i = 0; i < K; i++)
                sum -= missing[i];
            sum++;
            count = sum;
     //       cout << "Final sum being sent for answer is " << sum << endl;
        }
        if (count%2 == 0)
            cout << "Mom" << endl;
        else
            cout << "Chef" << endl;
    }
}
