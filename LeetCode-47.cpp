#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <iterator>


using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num)
    {
        sort (num.begin(), num.end());
        vector<vector<int>> ans;
        bool check = 1;
        while(check == 1)
        {
            ans.push_back(num);
            check = next_permutation(num.begin(), num.end());
        }
        return ans;
    }
};
