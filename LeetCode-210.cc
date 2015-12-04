class Solution {
public:
  void recur(vector<vector<int>> &adj, vector<int> &visited, vector<int> &cycle, queue<int> &nodes, int current, int &valid)
  {
    if (cycle[current] == 1)
      valid = 0;
    if (valid == 0)
      return;
    if (visited[current] == 1)
      return;
    cycle[current] = 1;
    visited[current] = 1;
    for (int i = 0; i < adj[current].size(); i++)
      recur(adj, visited, cycle, nodes, adj[current][i], valid);
    nodes.push(current);
    cycle[current] = 0;
    return;
  }  

  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prereq) 
  {
    vector<vector<int>> adj;
    adj.resize(numCourses);
    for (int i = 0; i < prereq.size(); i++)
      adj[prereq[i].first].push_back(prereq[i].second);
    vector<int> visited;
    visited.resize(numCourses);
    vector<int> cycle;
    cycle.resize(numCourses);
    queue<int> nodes;
    int valid = 1;
    for (int i = 0; i < numCourses; i++)
      recur(adj, visited, cycle, nodes, i, valid);
    vector<int> ans;
    if (valid == 0)
      return ans;
    while (nodes.empty() != 1)
    {
      ans.push_back(nodes.front());
      nodes.pop();
    }
    return ans;
  }
};