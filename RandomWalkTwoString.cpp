/*
You   are   given   a   rectangular   grid   with   2   rows   and   N   columns.   The   top   row   is   labeled   1   and   the   bfottom   row   is   labeled   2.   The
columns are labeled from 1 to N in increasing order. Each cell in the grid contains a single character.
Consider   a   hamiltonian   walk   in   this   grid.   Meaning,   pick   a   starting   cell,   say   (i,j),   and   consider   a   path   that   starts   from   (i,j)   and
goes   through   every   cell   in   the   grid   exactly   once.   Note   that   you   can   only   walk   to   adjacent   cells,   or   cells   that   you   share   a
common   edge   with.   There   may   be   several   such   paths.   Let   us   concatenate   the   characters   in   the   order   in   which   the   cells   are
visited during a walk. The string formed can be called the string for the walk.
Among   all   the   possible   walks,   and   their   respective   strings,   find   out   the   lexicographically   smallest   string.   We   know   that   the
length   of   the   strings   are   all   the   same   ­   to   be   precise,   2N.   Thus,   the   lexicographically   smallest   string   is   simply   the   alphabetically
smallest string if you compare the characters from left to right.
Input
The   first   line   of   input   contains   a   number   T,   the   number   of   test   cases.   Then   follow   T   test   cases.   Each   test   case   contains   3   lines.
The   first   line   contains   the   number   N,   the   number   of   columns   in   the   grid.   It   is   well   known   of   course   that   the   grid   contains   2   rows.  The   next   two   lines   contain   the   description   of   the   grid   in   the   form   of   two   strings;   the   string   of   N   characters   in   row   1   from   left   to
right and the string of N characters in row 2 from left to right, respectively. Each character will be a lowercase english letter.
Output
Output   a   single   line   for   each   test   case.   The   line   must   contain   a   string   with   2N   characters.   This   string   should   be   the
lexicographically smallest string for some hamiltonian walk in the grid.
Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 10


Sample Input
2
3
abc
def
10
ababaaabab
bababababa

Sample Output
abcfed
aaababababababababab

Explanation   In the first test the possible strings are { abcfed, adebcf, adefcb, badefc, bcfeda, cbadef, cfedab,
cfebad, dabcfe, dabefc, defcba, edabcf, efcbad, fedabc, fcbade, fcbeda }. The smallest string is abcfed.

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>

using namespace std;

bool check_index(int length, int x, int y, bool* top, bool* bottom)
{
    if ((y < length) && (y >= 0) && (x > -1) && (x < 2))
    {
        if (x == 0)
        {
            if (top[y] == 1)
                return false;
        }
        else
        {
            if (bottom[y] == 1)
                return false;
        }
        return true;
    }
    else
        return false;
}

string greedyWalk(string a, string b, int x, int y, bool* top, bool* bottom, string current)
{
    if (current.length() == 2*a.length())
        return current;
    int mx[] = {0,0,1,-1};
    int my[] = {-1,1,0,0};
    string ans = "||||";
    for (int i = 0; i < 4; i++)
    {
        int newx = x+mx[i];
        int newy = y+my[i];
        if (check_index(a.length(), newx, newy, top, bottom))
        {
            if (newx == 0)
            {
                top[newy] = 1;
                ans = min(ans, greedyWalk(a,b,newx,newy, top, bottom, current + a[newy]));
            }
            if (newx == 1)
            {
                bottom[newy] = 1;
                ans = min(ans, greedyWalk(a,b,newx,newy, top, bottom, current + b[newy]));
            }
        }
    }
    return ans;
}


int main()
{
    int T;
    cin >> T;
    for (int countt = T;countt > 0; countt--)
    {
        int N;
        cin >> N;
        string a;
        string b;
        cin >> a >> b;
        char mina = a[0];
        for  (int i = 0; i < a.length(); i++)
        {
            if (mina > a[i])
                mina = a[i];
        }
        for (int i = 0; i < b.length(); i++)
        {
            if (mina > b[i] )
                mina = b[i];
        }
        string answer = "||||";
        bool* av = new bool[a.length()];
        for (int i = 0; i < a.length(); i++)
            av[i] = 0;
        bool* bv = new bool[a.length()];
        for (int i = 0; i < a.length(); i++)
            bv[i] = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == mina)
            {
     //           cout << "calling greedy function for index " << i << endl;
                av[i] = 1;
                answer = min(answer, greedyWalk(a,b, 0, i, av, bv, string(1, a[i])));
     //           cout << "answer after greedying top row is " << answer << endl;
                for (int i = 0; i < a.length(); i++)
                    av[i] = 0;
                for (int i = 0; i < a.length(); i++)
                    bv[i] = 0;
            }
        }
        for (int i = 0; i < a.length(); i++)
        {
            if (b[i] == mina)
            {
     //           cout << "calling greedy function for index " << i << endl;
                bv[i] = 1;
                answer = min(answer, greedyWalk(a,b, 1, i, av, bv,  string(1, b[i])));
      //          cout << "answer after greedying bottom row is " << answer << endl;
                for (int i = 0; i < a.length(); i++)
                    av[i] = 0;
                for (int i = 0; i < a.length(); i++)
                    bv[i] = 0;
            }
        }
        cout << answer << endl;
    }

}

