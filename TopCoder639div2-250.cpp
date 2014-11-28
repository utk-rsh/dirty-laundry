#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class   ElectronicPetEasy
{
public:
bool look(vector<int> a, int b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b)
            return true;
    }
    return false;
}

string isDifficult(int s1, int p1, int t1, int s2, int p2, int t2)
{
    vector<int> current1;
    int c = 0;
    while (t1 > 0)
    {

        current1.push_back(s1+c*p1);
        c++;
        t1--;
    }
    current1.push_back(-1);
    c = 0;
    while (t2 > 0)
    {
        if (look(current1, s2+c*p2))
            return "Difficult";
        c++;
        t2--;
    }
    return "Easy";
}
};
