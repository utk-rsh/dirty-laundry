#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class EllysSubstringSorter
{
public:
string getMin(string S, int L)
{
    string ans = S;
    for (int i = 0; i < S.length() - L; i++)
    {
        string pre = S.substr(0,i);
        string a = S.substr(i,L);
        string b = S.substr(i+L, S.length() - L);
        cout << pre << "  .  " << a << "  .  " << b << endl;
        sort(a.begin(), a.end());
        string temp = pre + a + b;
        ans = min(ans, temp);
    }
    return ans;

}

};
