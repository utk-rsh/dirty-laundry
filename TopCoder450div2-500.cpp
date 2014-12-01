#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class OrderedNim
{
public:
string winner(vector<int> layout)
{
    int current = 0;
    for (int i = 0; i < layout.size() - 1; i++)
    {
        if (layout[i] == 1)
            current = (current+1)%2;
    }
    if (current == 0)
        return "Alice";
    else
        return "Bob";

}
};
