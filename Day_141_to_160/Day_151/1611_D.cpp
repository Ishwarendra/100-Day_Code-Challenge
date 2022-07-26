#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    int root = -1;
    std::vector<int> b(n), p(n);
    std::vector<std::vector<int>> adj(n);
    std::map<int, int> id;

    for (int i = 0; i < n; ++i)  
    {
        std::cin >> b[i];
        b[i]--;
        if (b[i] == i)
            root = i;
        else
        {
            adj[i].push_back(b[i]);
            adj[b[i]].push_back(i);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
        p[i]--;
        id[p[i]] = i;
    }

    std::vector<int> distance(n), ans(n);
    std::function<void(int, int)> dfs;
    bool possible = true;

    dfs = [&](int u, int p)
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            if (id[v] < id[u])
                possible = false;
            dfs(v, u);
        }
    };

    dfs(root, -1);

    if (possible)
    {
        for (int i = 0; i < n; i++)
            distance[p[i]] = i;

        dfs = [&](int u, int p)
        {
            for (int v : adj[u])
            {
                if (v == p)
                    continue;

                ans[v] = distance[v] - distance[u];
                dfs(v, u);
            }
        };
        dfs(root, -1);
        for (int i : ans)
            std::cout << i << " ";
        std::cout << "\n";
    }
    else
        std::cout << "-1\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}