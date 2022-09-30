#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    std::set<int> root;
    for (int i = 0; i < n; ++i)
        root.emplace(i);

    for (int i = 0; i < n; ++i)
    {
        int len;
        std::cin >> len;

        for (int j = 0; j < len; ++j)
        {
            int v;
            std::cin >> v;
            v--;

            adj[i].emplace_back(v);
            adj[v].emplace_back(i);
            root.erase(v);
        }
    }

    int r = *root.begin();
    assert(root.size() == 1);

    int m = std::__lg(n) + 1;
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    std::vector<int> depth(n);

    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        dp[u][0] = p;
        depth[u] = depth[p] + 1;
        for (int v : adj[u])
        {
            if (v != p)
                dfs(v, u);
        }
    };
    dfs(r, r);

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; ++j)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
    }

    auto lca = [&](int u, int v)
    {
        if (depth[u] > depth[v])
            std::swap(u, v);

        int diff = depth[v] - depth[u];

        for (int i = m - 1; i >= 0; --i)
        {
            if ((diff >> i) & 1)
                v = dp[v][i], diff -= (1 << i);
        }

        assert(diff == 0);
        if (u == v)
            return u;

        for (int i = m - 1; i >= 0; --i)
        {
            if (dp[u][i] != dp[v][i])
                u = dp[u][i], v = dp[v][i];
        }

        u = dp[u][0], v = dp[v][0];
        assert(u == v);
        return u;
    };

    int q;
    std::cin >> q;

    for (int i = 1; i <= q; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        std::cout << lca(u, v) + 1 << "\n";
    }  
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; ++i)
    {
        std::cout << "Case " << i << ":\n";
        solve();
    }
    
    return 0;
}