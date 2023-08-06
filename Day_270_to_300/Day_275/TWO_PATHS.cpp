#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    constexpr int inf = 1e9;
    std::vector<int> dp(n);
    std::function<void(int, int)> dfs = [&](int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            dp[u] = std::max(dp[u], dp[v] + 1);
        }
    }; dfs(0, 0);

    

    return 0;
}