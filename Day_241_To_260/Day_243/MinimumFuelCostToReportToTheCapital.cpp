#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    i64 minimumFuelCost(std::vector<std::vector<int>>& roads, int seats) 
    {
        int n = std::size(roads) + 1;
        std::vector<int> adj[n];

        for (auto road : roads)
        {
            adj[road[0]].emplace_back(road[1]);
            adj[road[1]].emplace_back(road[0]);
        }

        i64 vehicle = 0;
        std::function<i64(int, int)> dfs = [&](int u, int p)
        {
            i64 ans = 1;
            bool leaf = true;
            for (auto v : adj[u]) 
            {
                if (v == p)
                    continue;

                leaf = false;
                i64 val = dfs(v, u);
                ans += val;
                vehicle += (val + seats - 1) / seats;
            }

            if (leaf)
                return 1LL;

            return ans;
        }; 

        dfs(0, 0);
        return vehicle;
    }
};

int main()
{
    return 0; 
}    