#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class PillarsDivTwo
{
public:
double heights(vector<int> height, double* maxx, double* minn, int w, int current_height, int prev_height, double rope, int index)
{
    double tempa = (double)(current_height - prev_height)*1.0;
    tempa = tempa*tempa;
    double tempb = (double)w*1.0;
    tempb = w*w;
    cout << "tempa and tempb are " << tempa << " " << tempb << endl;
    if (index != 0)
        rope += sqrt(tempa+tempb);
    cout << "current rope length is " << rope << " at index " << index << " with current height as " << current_height << endl;
    if (index == height.size() -1)
    {
        cout << "returning rope at end of traversal as " << rope << endl;
        return rope;
    }
 /*   if ((current_height == height[index]) && (maxx[index] > rope))
        return rope;
    if ((current_height == 1) && (minn[index] > rope))
        return 0;
    if (current_height == height[index])
        maxx[index] = rope;
    if (current_height == 1)
        minn[index] = rope;
*/    rope = max(heights(height, maxx, minn, w, height[index+1], current_height, rope, index+1), heights(height, maxx, minn, w, 1, current_height, rope, index+1));
    cout << "returning rope as " << rope << endl;
    return rope;


}

double maximalLength(vector<int> height, int w)
{
    double* maxx = new double[height.size()];
    double* minn = new double[height.size()];
    memset(maxx, 0, sizeof(maxx));
    memset(minn, 0, sizeof(minn));
    double ans1 = heights(height, maxx, minn, w, height[0], height[0], 0.0, 0);
    double ans2 = heights(height, maxx, minn, w, 1.0, 1.0, 0.0, 0);
    return max(ans1, ans2);
}
};

int main()
{
vector<int> a;
a.push_back(100);
a.push_back(2);
a.push_back(100);
a.push_back(2);
a.push_back(100);
PillarsDivTwo obj;
cout << obj.maximalLength(a, 4);
return 0;
}
