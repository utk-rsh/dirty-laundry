#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longest(string in)
{
  if (in.length() <= 2)
    return in.length();
  char a = in[0];
  int a_last = 0;
  int b_last = -1;
  char b = 'a';
  int counter = 1;
  while (counter < in.length())
  {
    if (in[counter] != a)
    {
      b = in[counter];
      int b_last = counter;
      break;
    }
    counter++;
  }
  if (counter == in.length())
    return in.length();
  int begin = 0;
  int ans = counter + 1;
  for (int i = counter; i < in.length(); i++)
  {
    if (in[i] != a && in[i] != b)
    {
      if (a_last > b_last)
      {
        b = in[i];
        b_last = i;
        begin = a_last;
      }
      else
      {
        a = in[i];
        a_last = i;
        begin = b_last;
      }
    }
    else if (in[i] == a)
      a_last = i;
    else if (in[i] == b)
      b_last = i;
    ans = max(ans, i - begin + 1);
  }
  ans = max(ans, (int)in.length() - begin);
  return ans;
}

int main()
{
  string test = "aaaaabbbbbbv";
  int ans = longest(test);
  cout << "Ans is " << ans << endl;
  return 0;
}

