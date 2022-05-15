#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// https://leetcode.com/problems/all-paths-from-source-to-target/
// Find all paths from 0 to n - 1 node
void dfs(int cur, int end, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &path, vector<vector<int>> &result)
{
    if (cur == end)
    {
        path.push_back(end);
        result.push_back(path);
        path.pop_back();
    }

    path.push_back(cur);
    vis[cur] = true;

    for(int &nb : adj[cur])
    {
        if (not vis[nb])
            dfs(nb, end, adj, vis, path);
    }
    vis[start] = true;
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graphs.size();
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> vis(n, false);
    dfs(0, n - 1, graph, vis, path, res);
}

int main()
{
    return 0;
}