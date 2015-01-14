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

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };


bool operator< (Interval a, Interval b)
{
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int change = 1;
        while (change != 0)
        {
            change = 0;
            vector<Interval> more;
            for (int i = 0; i < (int)intervals.size(); i++)
            {
                if ((intervals[i].end >= intervals[i+1].start) && (i != (int)intervals.size() - 1))
                {
                    int maxx = max(intervals[i].end, intervals[i+1].end);
                    change = 1;
                    int j = i+1;
                    for (j = i+1; j < intervals.size(); j++)
                    {
                        if (intervals[j-1].end >= intervals[j].start)
                            maxx = max(maxx, intervals[j].end);
                        else
                            break;
                    }
                    j--;
              //      cout << "i and j are " << i << "  " << j << endl;
                //    cout << "istart and jend are " << intervals[i].start << "  " << intervals[j].end << endl;
                    Interval to_add = Interval(intervals[i].start, maxx);
                    i = j;
                    more.push_back(to_add);
                }
                else
                    more.push_back(intervals[i]);
            }
        /*    cout << endl;
            cout << "The more vector now is ";
            for (int i = 0; i < more.size(); i++)
                cout << more[i].start << "-" << more[i].end << "  ";
            cout << endl;
          */  intervals = more;
            more.clear();
        }
        return intervals;
    }
};

int main()
{
    vector<Interval> a;
    Interval aa(1,3);
    Interval ab(1,3);
    Interval ac(5,10);
    Interval ad(15,18);
    Interval ae(11,12);
    a.push_back(aa);
    a.push_back(ab);
//    a.push_back(ac);
//    a.push_back(ad);
//    a.push_back(ae);
    Solution obj;
    vector<Interval> b = obj.merge(a);
    return 0;
}

