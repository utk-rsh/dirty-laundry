#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class PeacefulLine
{
    public:
    string makeLine(vector<int> x)
    {
        int maxx = 0;
        int lmax = 0;
        for (int i = 0; i < x.size(); i++)
        {
            lmax = 1;
            for (int j = i+1; j < x.size(); j++)
            {
                if (x[j] == x[i])
                    lmax++;
            }
            maxx = max(lmax,maxx);
        }
        if (maxx > (x.size()/2 + x.size()%2))
            return "impossible";
        else
            return "possible";
    }
};

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(1);
    PeacefulLine a;
    string ans = a.makeLine(test);
    cout << ans << endl;
    return 0;
}
