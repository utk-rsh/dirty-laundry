#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

#define INT_MAX 2,147,483,647
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        if (strs.size() == 0)
            return ans;
        if (strs.size() == 1)
            return strs[0];
        int i;
        for (i = 1; i <= (int)strs[0].length(); i++)
        {
            bool flag = 1;
            for (int j = 1; j < (int)strs.size(); j++)
            {
                if (i > (int)strs[j].length() || i > (int)strs[j-1].length() )
                {
                    flag = 0;
                    break;
                }
                if (strs[j].substr(0,i) != strs[j-1].substr(0,i))
                    flag = 0;
                if (flag == 0)
                    break;
            }
            if (flag == 0)
                return strs[0].substr(0,i-1);
        }
        if (i == (int)strs[0].length() + 1)
            return strs[0];
        return ans;
    }
};

int main()
{
    vector<string> test;
    test.push_back("b");
    test.push_back("b");
    Solution obj;
    string ans = obj.longestCommonPrefix(test);
    cout << "Ans is  " << ans << endl;
}
