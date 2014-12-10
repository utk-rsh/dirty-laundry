#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class PalindromicSubstringsDiv2
{
public:
int subodd(string a, int b)
{
    int ans = 1;
    int i= 1;
    while ((b+i < a.length()) && (b-i > -1))
    {
        if (a[b+i] == a[b-i])
        {
            ans++;
            i++;
        }
        else
            break;
    }
    return ans;
}

int subeven(string a, int b)
{
    int ans = 0;
    int i = 0;
    while ((b+i+1 < a.length()) && (b-i > -1))
    {
        if (a[b-i] == a[b+1+i])
        {
            ans++;
            i++;
        }
        else
            break;
    }
    return ans;
}

int count(vector<string> s1, vector<string> s2)
{
    string main = "";
    for (int i = 0; i < s1.size(); i++)
        main += s1[i];
    for (int i = 0; i < s2.size(); i++)
        main += s2[i];
    int ans = 0;
    for (int i = 0; i < main.length(); i++)
        ans += subodd(main, i);
    for (int i = 0; i < main.length()-1; i++)
        ans+= subeven(main,i);
    return ans;

}

};
