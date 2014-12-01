#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class StrangeComputer
{
public:
int setMemory(string mem)
{
    int countt = 0;
    int i = 0;
    if (mem[0] == '1')
            countt++;
    for (i = 1; i < mem.length(); i++)
    {

        if (mem[i] != mem[i-1])
            countt++;
    }
    return countt;

}
};
