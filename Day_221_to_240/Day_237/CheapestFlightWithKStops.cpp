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
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) 
    {
        std::vector<std::pair<int, int>> adj[n];
        for (auto flight : flights)    
            adj[flight[0]].emplace_back(flight[1], flight[2]);

        std::set<std::array<int, 3>> q; // {dist, node, stops}
        q.insert({0, src, 0});
        std::vector<std::vector<int>> dist(n, std::vector<int>(k + 3, inf));
        dist[src][0] = 0;

        while (!q.empty())
        {
            auto [d, u, stops] = *std::begin(q);
            q.erase(std::begin(q));

            if (stops > k)
                continue;

            for (auto [v, cost] : adj[u])
            {
                if (cost + d < dist[v][stops + 1])
                {
                    q.erase({dist[v][stops + 1], v, stops + 1});
                    dist[v][stops + 1] = cost + d;
                    q.insert({dist[v][stops + 1], v, stops + 1});
                }
            }
        }

        int min_dist = *std::min_element(std::begin(dist[dst]), std::end(dist[dst]));

        return (min_dist < inf ? min_dist : -1);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}