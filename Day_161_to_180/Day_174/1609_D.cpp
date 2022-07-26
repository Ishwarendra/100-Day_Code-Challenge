#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

class DSU
{
    std::vector<int> rnk, par;
public:
    std::multiset<int> max;
    int extra = 0;

    DSU(int n) : rnk(n, 1), par(n) 
    { 
        std::iota(par.begin(), par.end(), 0); 
        for (int i = 0; i < n; i++)
            max.emplace(1);
    }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
        {
            extra++;
            return false;
        }
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);
        
            max.emplace(rnk[p1] + rnk[p2]);
            max.erase(max.find(rnk[p2]));
            max.erase(max.find(rnk[p1]));

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

    DSU d(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;

        d.unite(x, y);

        auto it = (--std::end(d.max));
        int ans = 0;
        for (int i = 0; i <= d.extra; ++i)
            ans += *(it--);

        std::cout << --ans << "\n";
    }
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