#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> c(n);
    for (int i = 0; i < n; ++i)
        std::cin >> c[i];

    std::vector<int> adj[n];

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        std::cin >> x >> y;

        x--, y--;

        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    i64 ans = 0;
    std::function<int(int)> dfs;
    std::vector<int> vis(n);

    constexpr int inf = 1e9 + 10;

    dfs = [&](int u)
    {
        vis[u] = 1;
        int min = c[u];

        for (int v : adj[u])
        {
            if (!vis[v])
                min = std::min(min, dfs(v));
        }

        return min;
    };

    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
            ans += dfs(i);
    }

    std::cout << ans << "\n";
    
    return 0;
}