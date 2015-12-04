class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) 
  {
    vector<int> ans;
    if (nums.size() == 0)
      return ans;
    deque<pair<int,int>> deq;
    for (int i = 0; i < k; i++)
    {
      while (deq.empty() != 1)
      {
        if (nums[i] >= deq.back().first)
          deq.pop_back();
        else
          break;
      }
      deq.push_back(make_pair(nums[i],i));
    }
    ans.push_back(deq.front().first);
    for (int i = k; i < nums.size(); i++)
    {
      while(deq.empty() != 1 && i - deq.front().second >= k)
        deq.pop_front();
      while (deq.empty() != 1)
      {
        if (nums[i] >= deq.back().first)
          deq.pop_back();
        else
          break;
      }
      deq.push_back(make_pair(nums[i],i));
      ans.push_back(deq.front().first);
    }
    return ans;
  }
};

