#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define print(...) 1;
#endif

class Solution
{
    const int inf = 1e9;
public:
    std::vector<int> shortestAlternatingPaths(int n,
            std::vector<std::vector<int>>& redEdges,
            std::vector<std::vector<int>>& blueEdges)
    {
        std::vector<std::pair<int, int>> adj[n];
        for (auto &edge : redEdges)
            adj[edge[0]].emplace_back(edge[1], 0);

        for (auto &edge : blueEdges)
            adj[edge[0]].emplace_back(edge[1], 1);

        std::queue<std::array<int, 3>> q;
        q.push({0, 0, 0});
        q.push({0, 0, 1});

        std::vector<std::array<int, 2>> dist(n, { inf, inf });
        dist[0] = {0, 0};

        while (!q.empty())
        {
            auto [d, u, r_col] = q.front();
            q.pop();

            for (auto [v, g_col] : adj[u])
            {
                if (r_col == g_col)
                    continue;

                if (dist[v][g_col] > dist[u][r_col] + 1)
                {   
                    dist[v][g_col] = dist[u][r_col] + 1;
                    q.push({dist[v][g_col], v, g_col});
                }
            }
        }

        std::vector<int> ans;
        for (auto [r, g] : dist)
        {
            if (std::min(r, g) != inf)
                ans.emplace_back(std::min(r, g));
            else
                ans.emplace_back(-1);
        }

        return ans;
    }
};

int main()
{
    return 0;
}