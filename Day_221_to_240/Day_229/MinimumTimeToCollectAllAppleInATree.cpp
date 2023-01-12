#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple) 
    {
        std::vector<int> adj[n];
        for (auto edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        int root = 0;
        std::function<int(int, int)> dfs;
        dfs = [&](int u, int p) -> int
        {
            int ans = 0, leaf = 1;
            for (int v : adj[u])
            {
                if (v == p)
                    continue;
                leaf = 0;
                int cur_ans = dfs(v, u);
                if (cur_ans)
                    ans += cur_ans + 1;
            }

            int add = (u != root) and (ans > 0 or hasApple[u]);
            return ans + add;
        }; 

        return dfs(0, 0);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> edges;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;

        edges.push_back({u, v});
    }

    std::vector<bool> hasApple(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (x)
            hasApple[i] = true;
    }

    Solution sol;
    std::cout << sol.minTime(n, edges, hasApple);
    
    return 0;
}