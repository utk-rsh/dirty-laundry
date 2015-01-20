#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size()-1; i > -1; i--)
        {
            if ((i == 0) && (digits[i] == 9))
            {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
                break;
            }
            if (digits[i] != 9)
            {
                digits[i]++;
                break;
            }
            else
                digits[i] = 0;
        }
        return digits;
    }
};

int main()
{
    vector<int> test;
    test.push_back(9);
    test.push_back(9);
    Solution obj;
    vector<int> ans = obj.plusOne(test);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    return 0;
}
