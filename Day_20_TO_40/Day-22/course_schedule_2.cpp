#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

class Solution
{
    vi *adj;
public:
    vector<int> dfs(int n, vi &indegree)
    {
        vi res;
        vector<bool> vis(n);

        for(int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0)
                res.push_back(i);
        }

        for(int i = 0; i <res.size(); i++)
        {
            int node = res[i];
            for(int nb : adj[node])
            {
                indegree[nb]--;
                if (indegree[nb] == 0)
                    res.push_back(nb);
            }
        }

        if (res.size() < n)
            return {};
        return res;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        adj = new vi[numCourses];
        vi indegree(numCourses);

        for(vi pre : prerequisites) // 1 must be done before 0
        {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        vi ordering = dfs(numCourses, indegree);
        return ordering;
    }
};

// int main()
// {
//     return 0;
// }