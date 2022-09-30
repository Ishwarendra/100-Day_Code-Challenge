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
    int n;
    std::string s;
    std::cin >> n >> s;

    n *= 2;

    std::vector<int> val(n);
    for (int i = 0, x = 0; i < n; i++)
    {
        if (s[i] == ')')
            x--;
        else
            x++;

        val[i] = x;
    }

    DSU dsu(n);
    int cc = n;

    std::map<int, std::deque<int>> m;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '(')
        {
            int v = val[i];
            if (m.contains(v - 1))
            {
                int id = 0, en = n;

                if (m.contains(v - 2))
                    en = *(std::upper_bound(std::begin(m[v - 2]), std::end(m[v - 2]), i));

                while (id < std::size(m[v - 1]) and (v == 1 or m[v - 1][id] < en) and !dsu.same(i, m[v - 1][id]))
                    cc -= dsu.unite(i, m[v - 1][id++]);
            }
        }

        if (s[i] == ')')
            m[val[i]].push_front(i);
    }

    std::cout << cc << "\n";
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