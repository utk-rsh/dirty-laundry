#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int jump(int A[], int n)
    {
        if (n < 2)
            return 0;
        int current_max = A[0];
        int next_max = A[0] + 1;
        int jumps = 0;
        int current = 0;
        while (current < n - 1)
        {
            jumps++;
            next_max = 0;
            for (int i = current; i <= current + current_max; i++)
            {
                if (i == n-1)
                    break;
                next_max = max(next_max, i + A[i]);
            }
            current = current + current_max;
            current_max = next_max - current;
        }
        return jumps;
    }
};

int main()
{
    int A[] = {1,1};
    int n = 2;
    Solution obj;
    int ans = obj.jump(A, n);
    cout << "The final ans is " << ans << endl;
}
