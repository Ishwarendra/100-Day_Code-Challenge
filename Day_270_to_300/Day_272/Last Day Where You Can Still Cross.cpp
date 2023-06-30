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
    int latestDayToCross(int row, int col, std::vector<std::vector<int>>& cells) 
    {
        int n = std::size(cells);
        int left = 0, right = n;
        int ans = 0;

        auto good = [&](int mid)
        {
            std::vector a(row, std::vector(col, 0));
            for (int i = 0; i < mid; i++)
            {
                auto cell = cells[i];
                int x = cell[0], y = cell[1];
                x--, y--;
                a[x][y] = 1;
            }

            std::vector<std::array<int, 2>> dirs {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
            auto safe = [&](int i, int j)
            {
                return i >= 0 and j >= 0 and i < row and j < col and a[i][j] == 0;
            };

            auto bfs = [&]()
            {
                std::queue<std::pair<int, int>> q;
                for (int i = 0; i < col; i++)
                {
                    if (a[0][i] != 1)
                    {
                        q.emplace(0, i);
                        a[0][i] = -1;
                    }
                }

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (auto [dx, dy] : dirs)
                    {
                        if (safe(x + dx, y + dy))
                        {
                            q.emplace(x + dx, y + dy);
                            a[x + dx][y + dy] = -1;
                        }
                    }
                }

                for (int i = 0; i < col; i++)
                {
                    if (a[row - 1][i] == -1)
                        return 1;
                }

                return 0;
            }; 

            return bfs();
        };

        while (left <= right)
        {
            auto mid = (left + right) >> 1;
            if (good(mid))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;

    int k;
    std::cin >> k;

    std::vector a(k, std::vector(2, 0));
    for (int i = 0; i < k; i++)
        std::cin >> a[i][0] >> a[i][1];

    Solution sol;
    std::cout << sol.latestDayToCross(n, m, a);
    return 0; 
}    