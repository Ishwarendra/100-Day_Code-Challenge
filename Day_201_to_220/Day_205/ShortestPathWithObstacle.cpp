#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
    std::vector<std::pair<int, int>> dirs {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
public:
    int shortestPath(std::vector<std::vector<int>> &grid, int k)
    {
        int n = std::size(grid);
        int m = std::size(grid[0]);

        auto safe = [&](int i, int j)
        {
            return i >= 0 and j >= 0 and i < n and j < m;
        };

        const int inf = 1e9;
        std::vector dist(n, std::vector<std::vector<int>>(m, std::vector<int>(k + 1, inf)));
        dist[0][0][0] = 0;

        std::multiset<std::array<int, 4>> q;

        q.insert({0, 0, 0, 0});

        while (!q.empty())
        {
            auto [d, obs, x, y] = *q.begin();
            q.erase({d, obs, x, y});

            if (x == n - 1 and y == m - 1)
                return d;

            for (auto [dx, dy] : dirs)
            {
                if (!safe(x + dx, y + dy))
                    continue;

                x += dx, y += dy;

                if (grid[x][y] == 1 and obs < k and dist[x][y][obs + 1] > d + 1)
                {
                    q.erase({dist[x][y][obs + 1], obs + 1, x, y});
                    dist[x][y][obs + 1] = d + 1;
                    q.insert({dist[x][y][obs + 1], obs + 1, x, y});
                }
                else if (grid[x][y] == 0 and obs <= k and dist[x][y][obs] > d + 1)
                {
                    q.erase({dist[x][y][obs], obs, x, y});
                    dist[x][y][obs] = d + 1;
                    q.insert({dist[x][y][obs], obs, x, y});
                }

                x -= dx, y -= dy;
            }
        }

        int ans = inf;
        for (int i = 0; i <= k; i++)
            ans = std::min(ans, dist[n - 1][m - 1][i]);

        return (ans == inf ? -1 : ans);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; ++j)
            std::cin >> grid[i][j];

    Solution sol;
    std::cout << sol.shortestPath(grid, k);

    return 0;
}