#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    class DSU 
    {
        const int n;
        std::vector<int> par;
    public:
        DSU(int n) : n(n), par(n) { std::iota(std::begin(par), std::end(par), 0); } 
        int get(int u)
        {
            while (par[u] != u)
                u = par[u] = par[par[u]];
            return u;
        }
        bool unite(int u, int v)
        {
            int x = get(u), y = get(v);
            if (x == y)
                return false;

            if (par[y] < par[x])
                std::swap(x, y);
            par[y] = x;
            return true;
        }
    };
public:
    std::string smallestEquivalentString(std::string s1, std::string s2, std::string baseStr) 
    {   
        std::string ans;
        DSU dsu(26);

        int n = std::size(s1);
        for (int i = 0; i < n; i++)
            dsu.unite(s1[i] - 'a', s2[i] - 'a');

        for (auto &ch : baseStr)
            ans += char(dsu.get(ch - 'a') + 'a');

        return ans;        
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}