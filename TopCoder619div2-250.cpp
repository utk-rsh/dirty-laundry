#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class GoodCompanyDivTwo
{
public:
int countGood(vector<int> superior, vector<int> worktype)
{
    int ans = 0;
    int* works = new int[101];
    for (int i = 0; i < superior.size(); i++)
    {
        memset(works, 0, sizeof(works)*101);
        works[worktype[i]]++;
        for (int j = i; j < superior.size(); j++)
        {
            if (superior[j] == i)
                {works[worktype[j]]++;}
        }
        bool check = 1;
        for (int i = 0; i < 101; i++)
            if (works[i] > 1)
                {check = 0;}
        if (check == 1)
            ans++;
    }
    return ans;
}
};
