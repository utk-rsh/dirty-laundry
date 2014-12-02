#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class CasketOfStarEasy
{
public:

int helper(vector<int> current, int index, int answer)
{
    cout << "helper called with index and answer as " << index <<  "  " << answer << endl;
    if (current.size() == 2)
        return answer;
    answer += current[index-1]*current[index+1];
    current.erase(current.begin() + index);
    int best = 0;
    for (int i = 1; i < current.size() - 1; i++)
    {
        cout << "helper being called in loop" << endl;
        int temp = helper(current, i, answer);
        cout << "best and temp before choosing max is " << best << "  " << temp << endl;
        best = max(best, temp);
        cout << "best is " << best << endl;
    }
    cout << "helper returning values as " << answer << endl;
    if(answer < best)
        answer = best;
    return answer;

}

int maxEnergy (vector<int> weight)
{
    int ans = 0;
    for (int i = 1;i < weight.size()  - 1; i++)
    {
        cout << "the " << i << " iteration of maxEnergy is starting. Current ans is " << ans << endl << endl;
        ans = max(ans, helper(weight, i, 0));
    }
    return ans;
}

};

int main()
{
CasketOfStarEasy star;
vector<int> a;
a.push_back(100);
a.push_back(2);
a.push_back(1);
a.push_back(3);
a.push_back(100);
cout << star.maxEnergy(a);
return 0;


}


