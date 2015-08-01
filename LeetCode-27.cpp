#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem)
    {
      queue<int> q;
      for (int i = 0; i < n; i++)
      {
        if (A[i] == elem)
          q.push(i);
      }
      int i = n - 1;
      while (q.empty() == 0)
      {
        if (i == -1 || i < q.front())
          break;
        if (A[i] == elem)
          i--;
        else
        {
          A[q.front()] = A[i];
          q.pop();
          i--;
        }
      }
      return i + 1;
    }
};

int main()
{
  int a[] = {4, 5};
  Solution obj;
  int ans = obj.removeElement(a, 2, 5);
  cout << "Ans is " << ans << endl;
  return 0;
}
