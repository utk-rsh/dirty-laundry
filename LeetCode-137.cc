class Solution {
public:
  int singleNumber(vector<int>& nums) 
  {
    int one = 0;
    int two = 0;
    int three = 0xFFFFFFFF;
    for (int i = 0; i < nums.size(); i++)
    {
      int temp = nums[i];
      int bits1 = temp & one;
      int bits2 = temp & two;
      int bits3 = temp & three;
      one = one & ~bits1;
      two = two & ~bits2;
      three = three & ~bits3;
      one = one | bits3;
      two = two | bits1;
      three = three | bits2;
    }   
    return one;
  }
};


