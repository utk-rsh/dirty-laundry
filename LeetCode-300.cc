class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
      if (nums.size() == 0)
        return 0;
      vector<int> small;
      small.resize(nums.size());
      for (int i = 0; i < (int)nums.size(); i++)
      {
          int largest = 1;
          for (int j = i - 1; j >= 0; j--)
          {
            if (nums[j] < nums[i] && small[j] >= largest)
              largest = small[j]+1;
          }
          small[i] = largest;
      }
      int ans = 0;
      for (int i = 0; i < small.size(); i++)
        ans = max(ans, small[i]);
      return ans;
    }
};