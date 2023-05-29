#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    const int inf = 10;
  public:
    int findAnnouncementNodes(int n, int m, std::vector<int> &canBeHeardFrom, 
            int loudness, std::vector<std::vector<int>> &edges) 
    {
        std::vector<int> adj[n];
        for (auto edge : edges)
        {
            adj[edge[0] - 1].emplace_back(edge[1] - 1);
            adj[edge[1] - 1].emplace_back(edge[0] - 1);
        }

        for (auto &x : canBeHeardFrom)
            x--;

        std::vector<int> dp(n, -inf);
        std::set<int> hear(std::begin(canBeHeardFrom), std::end(canBeHeardFrom));

        std::function<void(int, int)> dfs;
        dfs = [&](int u, int p)
        {
            for (auto v : adj[u]) 
            {
                if (v == p)
                    continue;

                dfs(v, u);

                if (dp[v] != -inf)
                    dp[u] = std::max(dp[u], dp[v] + 1);
            }

            if (hear.count(u))
                dp[u] = std::max(dp[u], 0);
        }; dfs(0, 0);

        std::set<int> ans_nodes;

        if (dp[0] <= loudness)
            ans_nodes.emplace(0);

        dfs = [&](int u, int p)
        {
            for (int v : adj[u])
            {
                if (v == p)
                    continue;

                int old_dpu = dp[u];
                int old_dpv = dp[v];

                int mx = -inf;
                dp[u] = -inf;
                for (int child : adj[u])
                {
                    if (child == v)
                        continue;

                    mx = std::max(mx, dp[child]);
                }

                if (hear.count(u))
                    dp[u] = std::max(0, mx + 1);
                else if (mx != -inf)
                    dp[u] = mx + 1;

                mx = -inf;
                dp[v] = -inf;
                for (int child : adj[v])
                    mx = std::max(mx, dp[child]);

                if (hear.count(v))
                    dp[v] = std::max(0, mx + 1);
                else if (mx != -inf)
                    dp[v] = mx + 1;

                if (dp[v] <= loudness)
                    ans_nodes.emplace(v);
                
                dfs(v, u);

                dp[u] = old_dpu;
                dp[v] = old_dpv;
            }
        }; dfs(0, 0);

        return ans_nodes.size();
    }
};


int main()
{
    Solution sol;
    int n, m, loudness;
    std::cin >> n >> m >> loudness;

    std::vector<int> canBeHeardFrom(m);
    for (int i = 0; i < m; i++)
        std::cin >> canBeHeardFrom[i];

    std::vector edges(n - 1, std::vector(2, 0));
    for (int i = 0; i < n - 1; i++)
        std::cin >> edges[i][0] >> edges[i][1];

    std::cout << sol.findAnnouncementNodes(n, m, canBeHeardFrom, loudness, edges);

    return 0; 
}    