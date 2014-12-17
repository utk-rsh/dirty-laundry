#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class ForgetfulAddition
{
public:
int minNumber(string a)
{
    int ans = 100000000;
    for (int i = 1; i < a.length(); i++)
    {
        string ta = a.substr(0,i);
        string tb = a.substr(i, (a.length() - i));
        cout << "ta and tb are " << ta << " " << tb << endl;
        int temp = atoi(ta.c_str())+ atoi(tb.c_str());
        ans = min(ans, temp);
    }
    return ans;
}
};
