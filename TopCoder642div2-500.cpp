#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class LightSwitchingPuzzle
{
public:
string doit(string a, int index)
{
    cout << "do it begins " << endl;
    for (int i = 1; index*i < a.length(); i++)
    {
        int t = index*i;
        if (a[t] == 'N')
            a[t] = 'Y';
        else if (a[t] == 'Y')
            a[t] = 'N';
    }
    cout << "doit end" << endl;
    return a;
}

int minFlips(string state)
{
    int c = 0;
    state = "N" + state;
    for (int i = 1; i < state.length(); i++)
    {
        if (state[i] == 'Y')
            {
                c++;
                state = doit(state, i);
            }
        cout << "state is now " << state << endl;
    }
    return c;
}
};

int main()
{
LightSwitchingPuzzle obj;
cout<< obj.minFlips("YNYNYNYN");
return 0;
}
