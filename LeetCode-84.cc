class Solution {
public:
  int largestRectangleArea(vector<int>& height) 
  {
    stack<pair<int,int>> mystack;
    if (height.size() == 0)
      return 0;
    int ans = 0;
    mystack.push(make_pair(0,height[0]));
    int last_popped_start = 0;
    for (int i = 1; i < height.size(); i++)
    {
      if (height[i] > mystack.top().second)
      {
        mystack.push(make_pair(i, height[i]));
        continue;
      }
      if (height[i] == mystack.top().second)
        continue;
      while (mystack.empty() != 1 && height[i] < mystack.top().second)
      {
        ans = max(ans, (i-mystack.top().first)*mystack.top().second);
        last_popped_start = mystack.top().first;
        mystack.pop();
      }
      if (mystack.empty() == 1)
        mystack.push(make_pair(0, height[i]));
      else
        mystack.push(make_pair(last_popped_start, height[i]));
    }
    while (mystack.empty() != 1)
    {
      ans = max(ans, ((int)height.size() - mystack.top().first)*mystack.top().second);
      mystack.pop();
    }
    return ans;      
  }
};
