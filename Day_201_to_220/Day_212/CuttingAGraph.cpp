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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    DSU dsu(n);
    std::set<std::pair<int, int>> edges;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        edges.insert({--u, --v});
    }

    std::vector<std::array<int, 3>> query;
    while (k--)
    {
        std::string t;
        std::cin >> t;

        if (t == "cut")
        {
            int a, b;
            std::cin >> a >> b;
            query.push_back({--a, --b, 0});
            edges.erase({a, b});
            edges.erase({b, a});
        }
        else
        {
            std::array<int, 3> q;
            std::cin >> q[0] >> q[1];
            q[2] = 1;

            q[0]--, q[1]--;
            query.emplace_back(q);
        }
    }

    for (auto [u, v] : edges)
        dsu.unite(u, v);

    std::vector<std::string> ans;
    std::reverse(std::begin(query), std::end(query));
    print(edges);
    for (auto [u, v, type] : query)
    {
        if (type == 0)
            dsu.unite(u, v);
        else
            ans.push_back(dsu.same(u, v) ? "YES" : "NO");
    }
        
    std::reverse(std::begin(ans), std::end(ans));
    for (auto s : ans)
        std::cout << s << "\n";

    return 0;
}