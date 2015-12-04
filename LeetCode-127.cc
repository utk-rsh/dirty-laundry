class Solution {
public:
  int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) 
  {
    int count = 0;
    if (beginWord == endWord)
      return 0;
    queue<string> q;
    string delim = "$wa";
    q.push(beginWord);
    q.push(delim);
    while (q.empty() != 1)
    {
      string current = q.front();
      q.pop();
      if (current == delim)
      {
        count++;
        continue;
      }
      if (current == endWord)
        return count;
      string temp = current; 
      for (int i = 0; i < current.length(); i++)
      {
        current = temp;
        for (int j = 0; j < 26; j++)
        {
   current[i] = 'a' + j;
          if (current == endWord)
            return count+1;
          auto it = wordDict.find(current);
          if (it != wordDict.end())
          {
           q.push(current);
        }
      }
    }
    return 0;
  }
};