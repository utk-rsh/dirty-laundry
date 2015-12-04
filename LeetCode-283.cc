class Solution {
public:
  void moveZeroes(vector<int>& nums) 
  {
    int swap_index = -1;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
        swap_index--;
      swap_index++;
      if (i != swap_index && nums[i] != 0)
        swap(nums[i], nums[swap_index]);
    }
    return;     
  }
};