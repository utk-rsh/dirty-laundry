#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

// LeetCodeOJ: TwoSum
bool operator< (pair<int, int> a, pair<int, int> b)
    {return (a.first < b.first);}


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<pair<int,int> > pairs;
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++)
            pairs.push_back(make_pair(numbers[i],i));
        sort(pairs.begin(), pairs.end());
   //     cout << "sorted array is " << endl;
   //     for (int i = 0; i < pairs.size();  i++)
   //         cout << pairs[i].first << " ";
   //     cout << endl;
        for (int i = 0; i < numbers.size(); i++)
        {
            vector<pair<int,int> >::iterator check;
            int temp = pairs[i].first;
   //         pairs[i].first = 10*target;;
            pair <int, int> dummy = make_pair(target-pairs[i].first, 0);
            check = lower_bound(pairs.begin(), pairs.end(), dummy);
            pairs[i].first = temp;
    //        cout << "target is " << target << endl;
    //        cout << "pairs[i].first is " << pairs[i].first << endl;
    //        cout << "check - pairs.begin is " << check - pairs.begin() << " with i equal to " << i << endl;
            int in = check - pairs.begin();
    //        cout << "i is " << i << " in is " << in << endl;
    //        cout << "pairs i1 is " << pairs[i].first << " and pairs in1 is " << pairs[in].first << endl;
    //        cout << "pairs i2 is " << pairs[i].second << " and pairs in2 is " << pairs[in].second << endl;
            if ((check == pairs.end()) || ( i == in) || (pairs[i].first + pairs[in].first != target));
            else
            {
                ans.push_back(pairs[i].second+1);
                ans.push_back(pairs[in].second+1);
                sort(ans.begin(), ans.end());
                return ans;
            }
        }
    }
};

