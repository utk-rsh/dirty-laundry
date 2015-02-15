#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class BuildingTowers
{
public:
    long long between(int xi, long long a, int xj, long long b, long long k)
    {
        if (a > b)
            return between(xj,b,xi,a,k);
        int available = abs(xj - xi) - 1;
        while (a < b)
        {
            available--;
            a += k;
            if (available <= 0)
                return max(a,b);
        }
        bool flipper = 1;
        while (available > 0)
        {
            if (flipper)
            {
                b +=k;
                flipper = 0;
            }
            else
            {
                a += k;
                flipper = 1;
            }
            available--;
        }
        return max(a,b);
    }

    long long maxHeight (int N, int K, vector<int> x, vector<int> t)
    {
        if (x.size() == 0)
            return ((long long)(N-1))*(long long)K;
        vector<pair<int,int> > join;
        for (int i = 0; i < x.size(); i++)
            join.push_back(make_pair(x[i],t[i]));
        sort(join.begin(), join.end());
        for (int i = 0; i < x.size(); i++)
        {
            x[i] = join[i].first;
            t[i] = join[i].second;
 //           cout << "i is " << i << " and x[i] is " << x[i] << " and t[i] is " << t[i] << endl;
        }
        long long ans = between(1,0,x[0],t[0],K);
  //      cout << "max height with first building is " << ans << endl;
        t[0] = min((long long)t[0],(long long)(x[0]-1)*(long long)K);
        for (int i = 0; i < x.size() - 1; i++)
        {
            t[i+1] = min((long long)t[i+1],t[i]+ (long long)(x[i+1]-x[i])*(long long)K);
            long long temp = between(x[i],t[i],x[i+1],t[i+1],K);
   //        cout << " i is " << i << " and max height is " << temp << endl;
            ans = max(ans, temp);
        }
        long long temp = (long long)t[x.size()-1] + (long long)(N-x[x.size()-1])*(long long)K;
 //       cout << "height with last building is " << temp << endl;
        ans = max(ans, temp);
        return ans;
    }
};

int main()
{
    vector<int> x;
    x.push_back(2);
 /*   x.push_back(7);
    x.push_back(13);
    x.push_back(15);
    x.push_back(18);
  */  vector<int> t;
    t.push_back(3);
 /*   t.push_back(22);
    t.push_back(1);
    t.push_back(55);
    t.push_back(42);
  */  BuildingTowers obj;
    long long ans = obj.maxHeight(5,4,x,t);
    cout << "Final ans is " << ans << endl;
    return 0;
}
