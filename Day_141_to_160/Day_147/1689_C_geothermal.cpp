#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

// GEOTHERMAL

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; ++i)  
    {
        int u, v;
        std::cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int min = n;
    std::function<void(int, int, int)> dfs = [&](int u, int p, int d)
    {
        int deg = adj[u].size();
        
        if (u != 1)
            deg--;

        if (deg <= 1)
            min = std::min(min, d * 2 + deg + 1); 

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u, d + 1);
        }
    };

    dfs(1, 0, 0);
    std::cout << n - min << "\n";
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