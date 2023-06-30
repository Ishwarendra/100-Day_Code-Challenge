#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    constexpr static int inf = 1e9;
    std::vector<std::array<int, 2>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isKey(char ch) { return 'a' <= ch and ch <= 'z'; }
    bool isLock(char ch) { return 'A' <= ch and ch <= 'Z'; }
    int getId(char ch) 
    { 
        int res = ch - 'a';
        if (res < 0)
            return int(ch - 'A');
        return res;
    }
    int getBit(int x, int pos) { return x >> pos & 1; }

public:
    int shortestPathAllKeys(std::vector<std::string>& grid) 
    {
        int n = std::size(grid), m = std::size(grid[0]);
        auto f = [&](int i, int j) { return i * n + j; };

        std::array<int, 2> st{};
        int keys = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '@')
                    st = {i, j};
                keys += isKey(grid[i][j]);
            }
        }

        auto safe = [&](int i, int j)
        {
            return i >= 0 and j >= 0 and i < n and j < m and grid[i][j] != '#';
        };

        std::set<std::tuple<int, int, int, int>> s;
        s.emplace(0, st[0], st[1], 0);
        std::vector dp(n, std::vector(m, std::vector(1 << keys, inf)));
        dp[st[0]][st[1]][0] = 0;

        while (!s.empty())
        {
            auto [d, x, y, mask] = *std::begin(s);
            s.erase(std::begin(s));
            for (auto [dx, dy] : dirs)
            {
                if (!safe(x + dx, y + dy))
                    continue;

                x += dx, y += dy;

                if (isLock(grid[x][y]))
                {
                    if (dp[x][y][mask] > d + 1 and getBit(mask, getId(grid[x][y])))
                    {
                        s.erase({dp[x][y][mask], x, y, mask});
                        dp[x][y][mask] = d + 1;
                        s.emplace(dp[x][y][mask], x, y, mask);
                    }
                }
                else if (isKey(grid[x][y]))
                {   
                    int id = getId(grid[x][y]);
                    if (dp[x][y][mask | (1 << id)] > d + 1)
                    {
                        s.erase({dp[x][y][mask | (1 << id)], x, y, mask | (1 << id)});
                        dp[x][y][mask | (1 << id)] = d + 1;
                        s.emplace(dp[x][y][mask | (1 << id)], x, y, mask | (1 << id));
                    }
                }
                else
                {
                    if (dp[x][y][mask] > d + 1)
                    {
                        s.erase({dp[x][y][mask], x, y, mask});
                        dp[x][y][mask] = d + 1;
                        s.emplace(dp[x][y][mask], x, y, mask);
                    }
                }

                x -= dx, y -= dy;
            }
        }
        
        int ans = inf;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                ans = std::min(ans, dp[i][j][(1 << keys) - 1]);
        }

        return ans < inf ? ans : -1;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Solution sol;
    std::cout << sol.shortestPathAllKeys(a);
    return 0; 
}    