#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class ShufflingCardsDiv2
{
public:
bool exists(int k, vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == k)
            return true;
    return false;
}

string shuffle(vector<int> permutation)
{
    vector<int> revtop;
    vector<int> revbot;
    for (int i = 0; i < permutation.size(); i++)
    {
        if (i%2 == 0)
            revtop.push_back(permutation[i]);
        else
            revbot.push_back(permutation[i]);
    }
    vector<int> inittop;
    vector<int> initbot;
    for (int i = 1; i < permutation.size()+1; i++)
    {
        if (i < permutation.size()/2 + 1)
            inittop.push_back(i);
        else
            initbot.push_back(i);
    }
    int matches = 0;
    for (int i = 0; i < permutation.size()/2; i++)
    {
        if(exists(revtop[i], inittop))
            matches++;
    }
    int check = permutation.size()/2;
    check = (check+1)/2;
    if (matches == check)
        return "Possible";
    else
        return "Impossible";
}
};
