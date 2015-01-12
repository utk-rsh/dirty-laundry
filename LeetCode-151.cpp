#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

class Solution {
public:
    void reverseWords(string &s)
    {
        reverse(s.begin(), s.end());
        string ans = "";
        istringstream ss(s);
        do
        {
            string word;
            ss >> word;
            reverse(word.begin(), word.end());
    //        cout << "word is ." << word << "." << endl;
            ans += word;
            ans += " ";
        } while (ss);
        ans = ans.substr(0, ans.length() - 1);
        if (ans[ans.length()-1] == ' ')
            ans = ans.substr(0, ans.length()-1);
        s = ans;
    }
};

int main()
{
Solution a;
string test = "the blue";
a.reverseWords(test);
cout << "The answer is ." << test << "." << endl;
}
