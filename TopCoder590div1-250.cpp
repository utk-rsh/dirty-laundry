#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class FoxAndChess
{
public:
string ableToMove(string in, string out)
{
vector<int> rpos_in;
vector<int> rpos_out;
vector<int> lpos_in;
vector<int> lpos_out;
for (int i = 0; i < in.length(); i++)
    if (in[i] == 'R')
        rpos_in.push_back(i);
for (int i = 0; i < in.length(); i++)
    if (out[i] == 'R')
        rpos_out.push_back(i);
for (int i = 0; i < in.length(); i++)
    if (in[i] == 'L')
        lpos_in.push_back(i);
for (int i = 0; i < in.length(); i++)
    if (out[i] == 'L')
        lpos_out.push_back(i);

if (rpos_in.size() != rpos_out.size())
    return "Impossible";
if (lpos_in.size() != lpos_out.size())
    return "Impossible";

if (rpos_in.size() == 0)
    for (int i = 0; i < lpos_in.size(); i++)
        if (lpos_in[i] < lpos_out[i])
            return "Impossible";
if (lpos_in.size() == 0)
    for (int i = 0; i < rpos_in.size(); i++)
        if (rpos_in[i] > rpos_out[i])
            return "Impossible";
if ((lpos_in == lpos_out) && (rpos_in == rpos_out))
    return "Possible";

string init;
for (int i = 0; i < in.length(); i++)
    if (in[i] != '.')
        init += in[i];

string fin;
for (int i = 0; i < out.length(); i++)
    if (out[i] != '.')
        fin += out[i];

if (init != fin)
    return "Impossible";

return "Possible";
}
};
