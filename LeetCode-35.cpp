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
    int searchInsert(int A[], int n, int target)
    {
        vector<int> again(A, A+n);
        vector<int>::iterator c;
        c = lower_bound(again.begin(), again.end(), target);
        return c - again.begin();
    }
};
