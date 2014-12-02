#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class PikachuEasy
{
public:
string check(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == 'p')
        {
            if ( i == word.length() -1)
                return "NO";
            else if (word[i+1] != 'i')
                return "NO";
            i++;
        }
        else if (word[i] == 'k')
        {
            if ( i == word.length() -1)
                return "NO";
            else if (word[i+1] != 'a')
                return "NO";
            i++;
        }
        else if (word[i] == 'c')
        {
            if ( i >= word.length() - 2)
                return "NO";
            else if (word[i+1] != 'h')
                return "NO";
            else if (word[i+2] != 'u')
                return "NO";
            i++;
            i++;

        }
        else
            return "NO";
    }
    return "YES";
}
};
