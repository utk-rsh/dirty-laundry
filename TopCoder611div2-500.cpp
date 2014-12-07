#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class LCMSetEasy
{
public:
string include(vector<int> s, int x)
{
    for (int i = 0; i < s.size(); i++)
    {
 //       cout << " i is " << i << " and corresponding element is " << s[i] << endl;
        if (s.size() == 0)
            return "Impossible";
        if (x % s[i] != 0)
        {    s.erase(s.begin() + i);
            i--;}
    }
    for (int i = 0; i < s.size(); i++)
    {
        {if (s[i] == x)
            {
            return "Possible";}
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        int look = x/s[i];
        if (look%s[i] == 0)
            continue;
        else
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == look)
                    return "Possible";
            }
        }
    }
    return "Impossible";
}

};

int main()
{
vector<int> s;
s.push_back(100);
s.push_back(99);
s.push_back(98);
LCMSetEasy a;
cout << a.include(s, 99);
return 0;
}
