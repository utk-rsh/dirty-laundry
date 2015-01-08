//http://www.codechef.com/JAN15/problems/ONEKING

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
    scanf("%d",&N);
    vector<pair<int, int> > kingdoms;
    int c = 0;
    while (N > 0)
    {
        N--;
        int t1, t2;
        scanf("%d", &t1);
        scanf("%d", &t2);
        pair<int, int> entry = make_pair(t1, t2);
        kingdoms.push_back(entry);
        c++;
    }
    sort(kingdoms.begin(), kingdoms.end());
 //   cout << "KINGDOMS VECTOR IS:  ";
 //   for (int i = 0; i < c; i++)
 //       cout << kingdoms[i].first << " & " << kingdoms[i].second << " ----- "  ;
//    cout << endl << endl;
    int bombs = 0;
    int low = kingdoms[0].first;
    int high = kingdoms[0].second;
    for (int i = 0; i < c; i++)
    {
        bombs++;
   //     cout << "!!! i is " << i << " and high is " << high << " !!!!!" << endl;
        while (kingdoms[i].first <= high)
        {
            high = min(high, kingdoms[i].second);
            i++;
            if (i >= c)
                break;
     //       cout << "i increased to " << i << " . global high is " << high << " and current high is " << kingdoms[i].second << " and current low is " << kingdoms[i].first << endl;
        }
        if (i == c - 1)
            bombs++;
        if (i >= c)
            break;
        high = kingdoms[i].second;
       // cout << " index i is now " << i << " with new high as " << high << " and number of bombs placed is " << bombs << endl;
    }
    printf("%d\n", bombs);
}
}

