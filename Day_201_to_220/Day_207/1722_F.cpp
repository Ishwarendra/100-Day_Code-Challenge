#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::array<int, 2>> dirs {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, -1}, { -1, 1}};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    auto check = [](std::vector<std::array<int, 2>> which)
    {
        for (auto [a, b] : which)
        {
            for (auto [c, d] : which)
            {
                if (std::abs(a - c) > 1 or std::abs(b - d) > 1)
                    return false;
            }   
        }

        return true;
    };

    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < m; ++y)
        {
            if (a[x][y] != '*')
                continue;

            std::vector<std::array<int, 2>> which(1, {x, y});
            int cnt = 0;
            for (auto [dx, dy] : dirs)
            {
                if (!safe(x + dx, y + dy))
                    continue;

                x += dx, y += dy;

                if (a[x][y] == '*')
                {
                    cnt++;
                    which.push_back({x, y});
                }

                x -= dx, y -= dy;
            }

            if (cnt != 2 or !check(which))
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}