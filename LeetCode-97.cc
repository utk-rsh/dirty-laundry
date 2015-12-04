class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) 
  {
    if (s3.length() != s1.length() + s2.length())
      return false;
    if (s1 == "")
      return (s2 == s3);
    if (s2 == "")
      return (s1 == s3);
    if (s3 == "")
      return false;
    string temp1 = s1 + s2;
    string temp2 = s3;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    if (temp1 != temp2)
      return false;
    bool arr[s1.length()+1][s2.length()+1];
    arr[s1.length()][s2.length()] = true;
    for (int i = 0; i < s1.length(); i++)
    {
      if (s1[s1.length() - 1 - i] == s3[s3.length() - 1 - i])
        arr[s1.length() - 1  - i][s2.length()] =  true;
      else
        break;
    }
    for (int i = 0; i < s2.length(); i++)
    {
      if (s2[s2.length() - 1 - i] == s3[s3.length() - 1 - i])
        arr[s1.length()][s2.length() - 1 - i] =  true; 
      else
        break;
    }
    for (int i = s1.length() - 1; i > -1; i--)
    {
      for (int j = s2.length() - 1; j > -1; j--)
      {
        bool flag1 = (s1[i] == s3[i+j]);
        bool flag2 = (s2[j] == s3[i+j]);
        arr[i][j] = (flag1 & arr[i+1][j])|(flag2 & arr[i][j+1]);
      }
    }
    return arr[0][0];
  }
};
