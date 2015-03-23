#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class ThePermutationGameDiv2 {
public:
    int present(long long * a, int target, int len)
    {
        for (int i = 0; i < len; i++)
        {
          if (a[i] == target)
            return i;
        }
        return -1;
    }

    long long findMin(int N)
    {
      long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
      long long twos[] = {4, 8, 16, 32};
      long long threes[] = {9, 27};
      long long fives = {25};
      long long ans = 1;
      int n = N;
      while (n > 0)
      {
        if (present(primes, n, 11) != -1)
          ans *= primes[present(primes, n, 11)];
        else if (present(twos, n, 4) != -1)
          ans *= 2;
        else if (present(threes, n, 2) != -1)
          ans *= 3;
        else if (n == 25)
          ans *= 5;
        //cout << "N is " << n << " and ans is " << ans << endl;
        n--;
      }
      return ans;
    }
};

int main()
{
  ThePermutationGameDiv2 obj;
  int ans = obj.findMin(11);
  cout << "Ans is "<< ans << endl;
  return 0;
}
