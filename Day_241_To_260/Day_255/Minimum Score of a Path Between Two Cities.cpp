#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution2 
{
    const int inf = 1e5;
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) 
    {
        std::vector<std::pair<int, int>> adj[n];
        for (auto p : roads)
        {
            adj[p[0] - 1].emplace_back(p[1] - 1, p[2]);
            adj[p[1] - 1].emplace_back(p[0] - 1, p[2]);
        }

        int ans = inf;
        for (auto [v, w] : adj[0])
            ans = std::min(ans, w);

        auto bfs = [&](int src)
        {
            std::vector<int> d(n, inf);
            std::queue<std::pair<int, int>> q;
            q.emplace(src, d[src]);

            while (!q.empty())
            {
                auto [u, cost] = q.front();
                q.pop();

                for (auto [v, w] : adj[u])
                {
                    if (d[v] > std::min(w, d[u]))
                    {
                        d[v] = std::min(d[u], w);
                        q.emplace(v, d[v]);
                    }
                }
            }

            return d[n - 1];
        };

        return bfs(0);
    }
};

class Solution 
{
    const int inf = 1e9;
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) 
    {
        std::bitset<100000> b;
        
        std::vector<std::pair<int, int>> adj[n];
        for (auto p : roads)
        {
            adj[--p[0]].emplace_back(--p[1], p[2]);
            adj[p[1]].emplace_back(p[0], p[2]);
        }

        std::queue<int> q;
        q.emplace(0);
        b[0] = 1;

        int ans = inf;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (auto [v, w] : adj[u])
            {
                ans = std::min(ans, w);
                if (b[v] == 0)
                {
                    q.emplace(v);
                    b[v] = 1;
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0; 
}    