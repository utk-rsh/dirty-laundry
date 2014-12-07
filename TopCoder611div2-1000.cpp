#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class ElephantDrinkingEasy
{
public:
bool enclosed (vector<string> m, int x, int y)
{
    int c = 0;
    for (int i = x - 1; i > -1; i--)
    {
        if (m[i][y] == 'Y')
        {
            c++;
            break;
        }
    }
    for (int i = x + 1; i < m.size(); i++)
    {
        if (m[i][y] == 'Y')
        {
            c++;
            break;
        }
    }
    for (int i = y - 1; i > -1; i--)
    {
        if (m[x][i] == 'Y')
        {
            c++;
            break;
        }
    }
    for (int i = y + 1; i < m.size(); i++)
    {
        if (m[x][i] == 'Y')
        {
            c++;
            break;
        }
    }
    if (c == 4)
        return true;
    else
        return false;
}

int maxElephants (vector<string> m)
{
    int negate = 0;
    int total = 0;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m.size(); j++)
        {
            if (m[i][j] == 'Y')
            {
                total++;
                if (enclosed(m, i, j))
                    negate++;
            }
        }
    }
    return total - negate;
}

};
