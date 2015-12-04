class Solution {
public:
  int nthUglyNumber(int n) 
  {
    if (n == 0)  
      return 0;
    priority_queue<pair<long long,int>, std::vector<pair<long long,int>>, std::greater<pair<long long,int>>> q;
    q.push(make_pair(1LL,2));
    int count = 0;
    auto current = q.top();
    while (count < n)
    {
      current = q.top();
      q.pop();
      q.push(make_pair(current.first*5, 5));
      if (current.second != 5)
        q.push(make_pair(current.first*3, 3));
      if (current.second == 2)
        q.push(make_pair(current.first*2, 2));
      count++;
    }
    return current.first;   
  }
};

