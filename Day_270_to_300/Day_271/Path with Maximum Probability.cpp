#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, 
        std::vector<double>& succProb, int start, int end) 
    {
        std::vector<std::vector<std::pair<int, double>>> adj(n);
        for (int i = 0; i < std::size(edges); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }    

        std::vector<double> dp(n, -1);
        dp[start] = 1;

        const double eps = 1e-6;
        std::set<std::pair<double, int>, std::greater<std::pair<double, int>>> q;
        q.emplace(dp[start], start);

        while (!q.empty()) 
        {
            auto [_, u] = *std::begin(q);
            q.erase(std::begin(q));

            for (auto [v, p] : adj[u])
            {
                if (dp[v] == -1 or dp[v] < dp[u] * p)
                {
                    q.erase({dp[v], v});
                    dp[v] = dp[u] * p;
                    q.emplace(dp[v], v);
                }
            }
        }

        return (dp[end] >= -eps ? dp[end] : 0.);
    }
};

int main()
{
    return 0; 
}    