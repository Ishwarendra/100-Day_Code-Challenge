#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> adj[n];

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    std::vector<int> distance(n, -1);

    std::function<void(int, int, int)> dfs;
    long long ans = 0;

    dfs = [&](int cur, int par, int d)
    {
        distance[cur] = d;

        int more_found = 0;

        for (int nb : adj[cur])
        {
            if (distance[nb] != -1)
                continue;

            dfs(nb, cur, d + 1);
            if (distance[nb] > 2) 
                more_found = 1, distance[cur] = 1, distance[par] = 2;
        }

        if (more_found)
            ans++;
    };

    dfs(0, -1, 0);

    std::cout << ans << "\n";
    
    return 0;
}