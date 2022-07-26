#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<std::set<int>> adj(n);
    std::vector<int> degree(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace(--v);
        adj[v].emplace(u);
        degree[u]++;
        degree[v]++;
    }

    std::multiset<std::pair<int, int>> m;
    for (int i = 0; i < n; ++i)
        m.emplace(degree[i], i);

    while (!m.empty() and k--)
    {
        std::vector<int> del;
        
        while (!m.empty())
        {
            auto [deg, node] = *std::begin(m);

            if (deg <= 1)
            {
                del.push_back(node);
                m.erase(std::begin(m));
            }
            else
                break;
        }

        for (int u : del)
        {
            for (int v : adj[u])
            {
                adj[v].erase(u);
                m.erase({degree[v], v});
                degree[v]--;

                m.emplace(degree[v], v);
            }

            m.erase({degree[u], u});
        }
    }

    std::cout << std::size(m) << "\n";
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