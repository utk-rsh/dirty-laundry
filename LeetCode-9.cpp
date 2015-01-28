#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

#define INT_MAX 2,147,483,647
using namespace std;

class Solution {
public:
    bool isPalindrome(int b)
    {
        long long a = (long long)b;
        if (a < 0)
            return 0;
        if (a == -2147483648)
            return 0;
        int length = 0;
        long long temp = a;
        while (temp > 0)
        {
            length++;
            temp = temp/10;
        }
        if (length == 1)
            return 1;
   //     cout << "length is " << length << endl;
        long long f = 10;
        long long o = pow(10,length);
        long long ff = 1;
        long long oo = pow(10,length-1);
        for (int i = 0; i < length/2; i++)
        {
            if ((a%f)/ff != (a%o)/oo)
                return 0;
            f = f*10;
            o = o/10;
            ff = ff*10;
            oo = oo/10;
        }
        return 1;
    }
};

int main()
{
Solution obj;
bool ans = obj.isPalindrome(1000000001);
cout << "ispalindrome is " << ans << endl;
return 0;
}
