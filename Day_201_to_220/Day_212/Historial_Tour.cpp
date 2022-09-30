#include <bits/stdc++.h>

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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n], rev[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace_back(--v);
        rev[v].emplace_back(u);
    }

    std::vector<std::vector<int>> sccs;

    std::vector<int> vis(n), order;
    std::function<void(int)> dfs = [&](int u)
    {
        vis[u] = 1;

        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v);
        }

        order.push_back(u);
    };

    for (int i = 0; i < n; ++i)
        if (!vis[i])
            dfs(i);

    std::reverse(std::begin(order), std::end(order));
    std::fill(std::begin(vis), std::end(vis), 0);

    std::function<void(int, std::vector<int> &)> rev_dfs = [&](int u, std::vector<int> &val)
    {
        vis[u] = 1;
        val.push_back(u);

        for (int v : rev[u])
        {
            if (!vis[v])
                rev_dfs(v, val);
        }
    };

    for (int i : order)
    {
        if (!vis[i])
        {
            sccs.push_back({});
            rev_dfs(i, sccs.back());
            std::sort(std::begin(sccs.back()), std::end(sccs.back()));
        }
    }

    int cur = 0;
    
    for (auto scc : sccs)
    {
        if (scc.front() == cur and std::size(scc) == 1 + scc.back() - scc.front())
            cur = scc.back() + 1;
        else
        {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";
    
    return 0;
}