#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <bitset>

using namespace std;

class Solution {
public:
    void all (vector<int> &S, vector<int> chhota, vector<vector<int>> *ans, int i)
    {
        if (i == S.size())
        {
            (*ans).push_back(chhota);
            return;
        }
        all(S, chhota, ans, i+1);
        chhota.push_back(S[i]);
        all(S, chhota, ans, i+1);
        return;
    }

    vector<vector<int> > subsets(vector<int> &S)
    {
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size() - 1; i++)
        {
            if (S[i] == S[i+1])
            {
                S.erase(S.begin()+i);
                i--;
            }
        }
        vector<vector<int>> *ans = new vector<vector<int>>;
        vector<int> chhota;
        all(S, chhota, ans, 0);
        return *ans;
    }
};

int main()
{
vector<int> test;
test.push_back(1);
test.push_back(2);
test.push_back(3);
Solution obj;
vector<vector<int>> ans = obj.subsets(test);
cout << "returned with ans size " << ans.size() << endl;
cout << ans[6].size() << " --  " << "-" << " " << ans[1][0] << " " << ans[2][0] << " " << ans[3][0] << " " << ans[4][0] << " " << ans[5][0] << " " << ans[6][0] << " " << ans[7][0] << endl;
cout << ans[7].size() << " --  " << "-" << " " << "-" << " " << "-" << " " << ans[3][1] << " " << "-"<< " " << ans[5][1] << " " << ans[6][1] << " " << ans[7][1] <<  endl;
cout << ans[5].size() << " --  " << "-" << " " << "-" << " " << "-" << " " << "-" << " " << "-"<< " " << "-"<<  " " << "-" << " " << ans[7][2] << endl;
}
