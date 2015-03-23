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
        if (index >= input->size())
          return;
        if (target < 0)
          return;
        if (input->at(index) == target)
        {
          current->push_back(input->at(index));
          ans->push_back(*current);
          current->pop_back();
          return;
        }
        recur(ans, current, input, target, index+1);
        for (int i = index; i < input->size(); i++)
        {
          current->push_back(input->at(i));
          recur(ans, current, input, target - input->at(i), i+1);
          current->pop_back();
        }
        return;
        }

      vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
      {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> current;
        recur(&ans, &current, &candidates, target, 0);
        sort(ans.begin(), ans.end());
        for (int i = 1; i < ans.size(); i++)
        if (ans[i] == ans[i-1])
        {
          ans.erase(ans.begin() + i);
          i--;
        }
        return ans;
      }
  };

int main()
{
  vector<int> input;
  input.push_back(10);
  input.push_back(1);
  input.push_back(2);
  input.push_back(7);
  input.push_back(6);
  input.push_back(1);
  input.push_back(5);
  Solution obj;
  vector<vector<int> > ans = obj.combinationSum2(input, 8);
  cout << "ans size is " << ans.size() << endl;
  cout << "first element size " << ans[0].size() << endl;
  for (int i = 0; i < ans[0].size(); i++)
    cout << ans[0][i] << " ";
  cout << endl << endl;
  cout << "second element size " << ans[1].size() << endl;
  for (int i = 0; i < ans[1].size(); i++)
    cout << ans[1][i] << " ";
  cout << endl << endl;
  cout << "third element size " << ans[2].size() << endl;
  for (int i = 0; i < ans[2].size(); i++)
    cout << ans[2][i] << " ";
  cout << endl << endl;
  cout << "fourth element size " << ans[3].size() << endl;
  for (int i = 0; i < ans[3].size(); i++)
    cout << ans[3][i] << " ";
  cout << endl << endl;
  return 0;
}
