#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
      int low = 0;
      int high = 0;
      int length = -1;
      int arr[260];
      memset(arr, -1, sizeof(arr));
      for (int i = 0; i < s.length(); i++)
      {
        int letter = s[i] ;
     //   cout << "letter is " << s[i] << " and high is " << high << " low is " << low <<  endl;
        if (arr[letter] == -1)
        {
     //     cout << arr[letter] << " arr letter with letter equal to " << letter << endl;
          arr[letter] = i;
        }
        else
        {
          length = max(length, high - low);
          while (low < high)
          {
            int old = s[low] ;
            low++;
            if (old == letter)
            {
              arr[letter] = i;
              break;
            }
            arr[old] = -1;
          }
        }
        high++;
      }
      length = max(length, high-low);
      return length;
    }
};

int main()
{
  Solution obj;
  string test =  "bbbbb";
  int ans = obj.lengthOfLongestSubstring(test);
  cout << "answer is " << ans << endl;
  return 0;
}
