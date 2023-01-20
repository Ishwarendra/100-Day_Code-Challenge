#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
    class DSU
    {
        const int n;
        std::vector<int> par, rnk;
    public:
        DSU(int n) : n(n), par(n), rnk(n, 1)
        {
            std::iota(std::begin(par), std::end(par), 0);
        }

        int get(int x)
        {
            while (x != par[x])
                x = par[x] = par[par[x]];
            return x;
        }

        bool unite(int x, int y)
        {
            int p1 = get(x), p2 = get(y);
            if (p1 == p2)
                return false;

            if (rnk[p1] < rnk[p2])
                std::swap(p1, p2);

            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;
            return true;
        }
    };
public:
    int numberOfGoodPaths(std::vector<int>& vals, std::vector<std::vector<int>>& edges)
    {
        int n = std::size(vals);
        int ans = n;
        std::vector<int> adj[n];

        for (auto &edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        DSU dsu(n);
        std::vector<std::pair<int, int>> val_id(n);

        for (int i = 0; i < n; i++)
            val_id[i] = {vals[i], i};
        std::sort(std::begin(val_id), std::end(val_id));

        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n and val_id[j].first == val_id[i].first)
            {
                int u = val_id[j].second;
                for (int v : adj[u])
                {
                    if (vals[v] <= vals[u])
                        dsu.unite(v, u);
                }

                j++;
            }

            j = i;
            std::map<int, int> m;
            while (j < n and val_id[j].first == val_id[i].first)
            {
                int u = val_id[j].second;
                m[dsu.get(u)]++;
                j++;
            }

            for (auto [_, f] : m)
                ans += 1LL * f * (f - 1) / 2;

            i = j - 1;
        }
        
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> vals(n);
    std::vector<std::vector<int>> edges(n - 1, std::vector<int>(2));

    for (int i = 0; i < n - 1; i++)
        std::cin >> edges[i][0] >> edges[i][1];
    for (int i = 0; i < n; i++)
        std::cin >> vals[i];

    Solution sol;
    std::cout << sol.numberOfGoodPaths(vals, edges);

    return 0;
}