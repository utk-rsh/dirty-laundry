#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

// CodeChef-ANUTHM

int main()
{
int T;
scanf("%d",&T);
while (T > 0)
{
    T--;
    int N, M;
    scanf("%d",&N);
    scanf("%d",&M);
    float ans = M+N-1;
    printf("%f\n", ans);
}
return 0;
}
