#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
    const int inf = 1e9;
public:
    int closestMeetingNode(std::vector<int>& edges, int node1, int node2) 
    {
        int n = std::size(edges);
        auto bfs = [&](int u)
        {
            std::queue<int> q;
            q.emplace(u);
            std::vector<int> dist(n, inf);
            dist[u] = 0;

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                int child = edges[cur];
                if (child == -1 or dist[child] < inf)
                    continue;

                dist[child] = dist[cur] + 1;
                q.emplace(child);
            }

            return dist;
        };    

        auto dist1 = bfs(node1);
        auto dist2 = bfs(node2);

        int ans = inf;
        int id = -1;

        for (int i = 0; i < n; i++)
        {
            if (ans > std::max(dist1[i], dist2[i]))
            {
                ans = std::max(dist1[i], dist2[i]);
                id = i;
            }
        }

        return id;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, n1, n2;
    std::cin >> n >> n1 >> n2;

    std::vector<int> edges(n);
    for (int i = 0; i < n; i++)
        std::cin >> edges[i];

    Solution sol;
    std::cout << sol.closestMeetingNode(edges, n1, n2);
    
    return 0;
}