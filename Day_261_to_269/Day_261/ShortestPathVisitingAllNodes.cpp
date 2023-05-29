#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution
{
    const int inf = 1e9;
    std::vector<std::vector<int>> allPairShortestPath(std::vector<std::vector<int>> &adj)
    {
        int n = std::size(adj);
        std::vector d(n, std::vector<int>(n, inf));
        for (int i = 0; i < n; i++)
        {
            d[i][i] = 0;
            for (auto v : adj[i])
                d[i][v] = d[v][i] = 1;
        }

        for (int p = 0; p < n; p++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    d[i][j] = std::min(d[i][j], d[i][p] + d[p][j]);
            }
        }

        return d;
    }
public:
    int shortestPathLength(std::vector<std::vector<int>>& adj)
    {
        int n = std::size(adj);
        auto d = allPairShortestPath(adj);
        int ans = inf;

        const int m = 1 << n;
        std::vector dp(n, std::vector(m, inf));
        for (int i = 0; i < n; i++)
            dp[i][0] = 0;

        std::function<int(int, int)> f = [&](int u, int mask)
        {
            if (dp[u][mask] != inf)
                return dp[u][mask];

            for (int i = 0; i < n; i++)
            {
                if (mask >> i & 1)
                    dp[u][mask] = std::min(dp[u][mask], f(i, mask ^ (1 << u)) + d[i][u]);
            }

            return dp[u][mask];
        };

        for (int i = 0; i < n; i++)
            ans = std::min(ans, f(i, m - 1));

        return ans;
    }
};

int main()
{
    return 0;
}