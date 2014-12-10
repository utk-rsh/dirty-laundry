#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class ChristmasTreeDecorationDiv2
{
public:
int solve(vector<int> col, vector<int> x, vector<int> y)
{
    int a = 0;
    for (int i = 0; i < col.size()-1; i++)
    {
        if(col[x[i]-1] != col[y[i]-1])
            a++;
    }
    cout << "ans is " << a << endl;
    return a;

}

};
