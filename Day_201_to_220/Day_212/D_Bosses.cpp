#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct DSU
{
    std::vector<int> par, steps;
    const int n;

    DSU(int n) : n(n), par(n), steps(n) { std::iota(std::begin(par), std::end(par), 0); }
    
    std::pair<int, int> get(int a)
    {
        if (a == par[a])
            return {par[a], 0};

        auto [p, val] = get(par[a]);
        steps[a] += steps[par[a]];
        par[a] = p;
        
        return {par[a], steps[a]};
    }

    void unite(int a, int b)
    {
        par[a] = b;
        steps[a] = 1;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    DSU dsu(n);

    while (m--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int a, b;
            std::cin >> a >> b;
            a--, b--;

            dsu.unite(a, b);
        }
        else
        {
            int a;
            std::cin >> a;
            a--;

            std::cout << dsu.get(a).second << "\n";
        }
    }

    return 0;
}