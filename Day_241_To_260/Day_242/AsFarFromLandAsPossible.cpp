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
    int maxDistance(std::vector<std::vector<int>>& grid) 
    {
        int n = std::size(grid);
        std::vector<std::array<int, 2>> dirs { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };        
        std::vector dist(n, std::vector<int>(n, inf));

        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    q.emplace(i, j), dist[i][j] = 0;
            }
        }

        auto safe = [&](int i, int j)
        {
            return i >= 0 and j >= 0 and i < n and j < n;
        };

        int ans = -1;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (!grid[x][y])
                ans = std::max(ans, dist[x][y]);

            for (auto [dx, dy] : dirs)
            {
                if (safe(x + dx, y + dy) and dist[x + dx][y + dy] == inf)
                {
                    q.emplace(x + dx, y + dy);
                    dist[x + dx][y + dy] = dist[x][y] + 1;
                }
            }
        }

        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}