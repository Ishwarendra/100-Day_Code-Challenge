#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i)  
    {
        int u, v;
        std::cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    std::vector<int> depth(n + 1, -1);
    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        int deg = 0;
        depth[u] = depth[p] + 1;

        for (int v : adj[u])
        {
            if (v != p)
            {
                deg++;
                dfs(v, u);
            }
        }

        if (deg < 2)
            ans = std::max(ans, n - 2 * depth[u] - deg);
    };

    dfs(1, 0);
    std::cout << --ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}