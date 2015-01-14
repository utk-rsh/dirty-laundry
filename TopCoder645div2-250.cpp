#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BacteriesColony
{
public:
vector<int> performTheExperiment(vector<int> colonies)
{
    vector<int> change (colonies.size());
    int* todo = new int[colonies.size()];
    int check = 0;
    while (change != colonies)
    {
        if (check != 0)
            colonies = change;
        for (int i = 0; i < colonies.size(); i++)
                todo[i] = 0;
        for (int i = 1; i < colonies.size() - 1; i++)
        {
            if ((colonies[i] > colonies[i-1]) && (colonies[i] > colonies[i+1]))
                todo[i] = -1;
            if ((colonies[i] < colonies[i-1]) && (colonies[i] < colonies[i+1]))
                todo[i] = 1;
        }
        for (int i = 0; i < colonies.size(); i++)
        {
        //    cout << "i is " << i << " with todo i as " << todo[i] << " and colonies i as " << colonies[i] << endl;
            change[i] = colonies[i]+todo[i];
        }
        check = 1;
//        cout << "colonies is " << endl;
  //      for (int i = 0; i < colonies.size(); i++)
    //        cout << change[i] << " ";
      //  cout << endl;
    }
    return change;
}
};

int main()
{
    vector<int> test;
    test.push_back(5);
    test.push_back(3);
    test.push_back(4);
    test.push_back(6);
    test.push_back(1);
    BacteriesColony a;
    vector<int> ans = a.performTheExperiment(test);
    cout << ans[0] << endl;
    return 0;
}
