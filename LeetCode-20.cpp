#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> a;
        for (int i = 0 ; i < s.length(); i++)
        {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
                a.push(s[i]);
            else if ( (a.empty() == 0) && (s[i] == ')') && (a.top() == '('))
                a.pop();
            else if ((a.empty() == 0) && (s[i] == ']') && (a.top() == '['))
                a.pop();
            else if ((a.empty() == 0) && (s[i] == '}') && (a.top() == '{'))
                a.pop();
            else
                return false;
        }
        if (a.empty() == 1)
            return true;
        else
            return false;
    }
};
