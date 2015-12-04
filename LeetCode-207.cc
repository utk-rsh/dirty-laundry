class Solution {
public:
  bool dfs(int current, vector<vector<int>> &adj, unordered_set<int> &myset, vector<int> &visited)
  {
    if (myset.find(current) != myset.end())
      return false;
    if (visited[current] == 1)
      return true;
    visited[current] = 1;
    myset.insert(current);
    for (int i = 0; i < (int)adj[current].size(); i++)
    {
      if (dfs(adj[current][i], adj, myset, visited) == false)
        return false;
    }
    myset.erase(current);
    return true;
  }
    
  bool canFinish(int numCourses, vector<pair<int, int>>& prereq) 
  {
    if (prereq.size() == 0)
      return true;
    vector<vector<int>> adj;
    adj.resize(numCourses);
    for (int i = 0; i < prereq.size(); i++)
      adj[prereq[i].second].push_back(prereq[i].first);
    vector<int> visited;
    visited.resize(numCourses);
    unordered_set<int> myset;
    for (int i = 0; i < numCourses; i++)
    {
      if( dfs(i, adj, myset, visited) == false)
        return false;
    }
    return true;
  }
};
