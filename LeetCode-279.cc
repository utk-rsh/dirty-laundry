class Solution {
public:
  int numSquares(int n) 
  {
    if (n == 0)
      return 0;
    vector<int> squares;
    for (int i = 1; i*i <= n; i++)
      squares.push_back(i);
    vector<int> alpha = {n};
    vector<int> beta;
    vector<int> *a = &alpha;
    vector<int> *b = &beta;
    int count = 1;
    while (true)
    {
      for (auto rem : *a)
      {
        for (auto values : squares)
        {
   int temp = rem - values;
          if (temp == 0)
            return count;
          if (temp > 0)
            b->push_back(temp);
        }
      }
      count++;
      vector<int>* temp_p;
      temp_p = a;
      a = b;
      b = temp_p;
  }
  }
};
