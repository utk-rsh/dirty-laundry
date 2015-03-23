#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void recur(vector<vector<int> > *ans, vector<int> *current, vector<int> *input, int target, int index)
    {
      if (target == 0)
      {
        vector<int> cop = *current;
        sort(cop.begin(), cop.end());
        if (ans->size() == 0)
          ans->insert(ans->begin(), cop);
        else if (cop != (*ans)[0])
          ans->insert(ans->begin(), cop);
      }
      int counter = 0;
      while (target > -1)
      {
        if (index + 1 > input->size())
          break;
        recur(ans, current, input, target, index+1);
        target -= input->at(index);
        counter += 1;
        current->push_back(input->at(index));
      }
      while (counter > 0)
      {
        current->pop_back();
        target += input->at(index);
        counter--;
      }
      return;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
      vector<vector<int> > ans;
      vector<int> current;
      ans.reserve(1000);
      current.reserve(10000);
      recur(&ans, &current, &candidates, target, 0);
      return ans;
    }
};
