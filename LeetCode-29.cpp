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
    int divide(int dividend, int divisor){
        long long ans = 0;
        int sign = 0;
        long long ddividend = abs((long long)dividend);
        long long ddivisor = abs((long long)divisor);
        if (((long long)dividend < 0LL) && ((long long)divisor > 0LL))
            sign = 1;
        if (((long long)dividend > 0LL) && ((long long)divisor < 0LL))
            sign = 1;
        while (ddividend > 0)
        {
            if (ddividend < ddivisor)
                break;
            long long temp_d = ddivisor;
            long long multiplier = 1;
            ddividend -= ddivisor;
            ans++;
            while (ddividend >= 0)
            {
                if (ddividend < ddivisor)
                    goto out;
                ddividend -= temp_d;
                ans += multiplier;
                multiplier++;
                temp_d =  ddivisor*multiplier;
              //  cout << "is there a cycle " << dividend << "  " << temp_d << "  " << multiplier << "  " << ans << endl;
            }
            ddividend += temp_d;
            ans -= multiplier;
            //cout << "Dividend is " << dividend << endl;
          //  cout << "Divisor is " << divisor << endl;
        //    cout << "temp_d is " << temp_d << endl;
      //      cout << "Multiplier is " << multiplier << endl;
    //        cout << "Ans is " << ans << endl;
        }
        out:
        if (sign == 1)
            ans = 0LL - ans;
        if (ans > (long long)2147483647)
            return 2147483647;
        return ans;
    }
};

int main()
{
Solution obj;
cout << obj.divide(-2147483648, 1) << endl;
return 0;
}
