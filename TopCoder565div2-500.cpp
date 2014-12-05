#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class MonstersValley2
{
public:

int current(vector<int> dread, vector<int> price, int spent, int scary, int index)
{
    if (index == dread.size())
        return spent;
    if (scary < dread[index])
    {
        spent += price[index];
        scary += dread[index];
        spent = current(dread,price, spent, scary, index+1);
    }
    else
        spent = min(current(dread, price, spent, scary, index+1), current(dread, price, spent + price[index], scary+ dread[index], index+1));
    return spent;

}

int minimumPrice(vector<int> dread, vector<int> price)
{
    return current(dread, price, 0, 0, 0);
}

};
