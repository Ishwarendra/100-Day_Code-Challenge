#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

constexpr int inf = 1e9;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> outdeg(n);
    std::set<int> adj[n];
    std::map<std::pair<int, int>, int> freq;

    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].insert(v);
        outdeg[u]++;
        freq[{u, v}]++;
    }

    std::set<std::pair<int, int>> s;
    s.emplace(0, 0);
    std::vector<int> distance(n, inf), vis(n);
    distance[0] = 0;

    while (!s.empty())
    {
        auto [d, cur] = *s.begin();
        s.erase(s.begin());

        if (vis[cur])
            continue;   
        vis[cur] = 1;

        for (int nb : adj[cur])
        {
            if (!vis[nb] and distance[nb] > d + outdeg[cur] - freq[{cur, nb}] + 1)
            {
                s.erase({distance[nb], nb});
                distance[nb] = d + outdeg[cur] - freq[{cur, n}] + 1;
                s.insert({distance[nb], nb});
            }
        }
    }

    std::cout << distance[n - 1] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    
    while (t--)
        solve();
    
    return 0;
}