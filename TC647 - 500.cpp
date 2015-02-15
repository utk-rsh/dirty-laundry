#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class TravellingSalesmanEasy
{
    public:
    int getMaxProfit(int M, vector<int> profit, vector<int> city, vector<int> visit)
    {
        int pro = 0;
        for (int i = 0; i < visit.size(); i++)
        {
            int plmax = 0;
            int pli = -1;
            for (int j = 0; j < city.size(); j++)
            {
                if (city[j] == visit[i])
                {
                    if (profit[j] > plmax)
                    {
                        plmax = profit[j];
                        pli = j;
                    }
                }
            }
    //        cout << " i is " << i << " and visit i is " << visit[i] << endl;
     //       cout << "plmax is " << plmax << " and pli is " << pli << endl;
          //  cout << "profit element being removed is " << (*profit.begin()+pli) << endl;
            pro += plmax;
            if (pli != -1)
            {
                profit.erase(profit.begin()+pli);
                city.erase(city.begin()+pli);
            }
        }
        return pro;
    }

};

int main()
{
    vector<int> profit;
    profit.push_back(77);
    profit.push_back(33);
    profit.push_back(10);
    profit.push_back(68);
    profit.push_back(71);
    profit.push_back(50);
    profit.push_back(89);
    vector<int> city;
    city.push_back(4);
    city.push_back(1);
    city.push_back(5);
    city.push_back(6);
    city.push_back(2);
    city.push_back(2);
    city.push_back(1);
    vector<int> visit;
    visit.push_back(6);
    visit.push_back(5);
    visit.push_back(5);
    visit.push_back(6);
    visit.push_back(4);
  //  visit.erase(visit.begin()+1);
  //  cout << "visit0 is " << visit[0] << endl;
  //  cout << "visit 1 is " << visit[1] << endl;
    TravellingSalesmanEasy obj;
    int prof = obj.getMaxProfit(4,profit,city,visit);
    cout << "final ans is " << prof << endl;
}
