#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);
                
            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;                
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
}; 

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];
    std::multiset<std::pair<int, int>> a;

    for (int i = 0; i < n; ++i)  
    {
        int v;
        std::cin >> v;

        a.emplace(v, i);
    }

    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);

        auto [min, max] = std::minmax(u, v);
        edges.emplace_back(0, min, max);
    }

    i64 ans = 0;

    while (std::size(a) > 1)
    {
        auto [val1, u] = *std::begin(a);
        a.erase(std::begin(a));

        auto [val2, v] = *std::begin(a);

        auto [min, max] = std::minmax(u, v);
        edges.emplace_back(std::abs(val1 - val2), min, max);
    }

    std::vector<int> to_take;

    auto kruskal = [&]()
    {
        DSU dsu(n);

        std::sort(std::begin(edges), std::end(edges));

        int pos = -1;
        for (auto [w, u, v] : edges)
        {
            pos++;
            if (dsu.same(u, v))
                continue;

            dsu.unite(u, v);
            ans += w;
            to_take.emplace_back(pos);
        }
    };

    kruskal();
    assert(std::size(to_take) < 2 * n);

    std::cout << ans << " " << std::size(to_take) << '\n';
    for (auto i : to_take) 
        std::cout << std::get<1>(edges[i]) + 1 << " " << 1 + std::get<2>(edges[i]) << "\n";
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