class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) 
  {
    int xorred = 0;
    for (int i = 0; i < nums.size(); i++)
      xorred = xorred^(nums[i]);
    int val = xorred&(~(xorred-1));
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] & val)
        xor1 = xor1^nums[i];
      else
        xor2 = xor2^nums[i];
    }
    vector<int> ans {xor1, xor2};
    return ans;    
  }
};
