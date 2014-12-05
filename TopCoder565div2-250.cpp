#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class ValueHistogram
{
public:
vector<string> build(vector<int> values)
{
    int arr[10] = {0};
    for (int i = 0; i < values.size(); i++)
        arr[values[i]]++;


    int maxx = 0;
    for (int i = 0;i < 10; i++)
        if (arr[i] > maxx)
            maxx = arr[i];

    vector<string> ans;
    string in;
    for (int i = 0; i < 10; i++)
        in += '.';

    for (int i = 0; i <= maxx; i++)
    {
        string temp = in;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] > 0)
            {
                temp[i] = 'X';
                arr[i]--;
            }
        }
        ans.insert(ans.begin(), temp);
    }
    return ans;
}
};
