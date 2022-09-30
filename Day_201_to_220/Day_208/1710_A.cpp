#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto b = a;
    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    std::vector<std::array<int, 6>> ans;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            int cnt = 0;
            std::vector<std::array<int, 2>> zeroes, ones;
            for (auto [dx, dy] : dirs)
            {
                i += dx, j += dy;

                if (a[i][j] == '1')
                {
                    ones.push_back({i, j});
                    cnt++;
                }
                else
                    zeroes.push_back({i, j});

                a[i][j] = '0';
                i -= dx, j -= dy;
            }

            if (cnt == 4)
            {
                auto [x1, y1] = ones[1];
                auto [x2, y2] = ones[2];
                auto [x3, y3] = ones[3];

                zeroes.push_back(ones[1]);
                zeroes.push_back(ones[2]);
                zeroes.push_back(ones[3]);
                ones.pop_back();
                ones.pop_back();
                ones.pop_back();

                cnt = 1;
                ans.push_back({x1, y1, x2, y2, x3, y3});
            }

            if (cnt == 0)
                continue;
            else if (cnt == 1)
            {
                auto [x1, y1] = zeroes[0];
                auto [x2, y2] = zeroes[1];
                auto [x3, y3] = ones[0];
                ans.push_back({x1, y1, x2, y2, x3, y3});
                ans.push_back({x1, y1, x3, y3, zeroes[2][0], zeroes[2][1]});
                ans.push_back({x3, y3, zeroes[2][0], zeroes[2][1], x2, y2});
            }
            else if (cnt == 2)
            {
                auto [x1, y1] = zeroes[0];
                auto [x2, y2] = zeroes[1];
                auto [x3, y3] = ones[0];
                auto [x4, y4] = ones[1];

                ans.push_back({x1, y1, x2, y2, x3, y3});
                ans.push_back({x1, y1, x2, y2, x4, y4});
            }
            else if (cnt == 3)
            {
                auto [x1, y1] = ones[0];
                auto [x2, y2] = ones[1];
                auto [x3, y3] = ones[2];

                ans.push_back({x1, y1, x2, y2, x3, y3});
            }
        }
    }

    std::cout << std::size(ans) << "\n";
    for (auto &[x1, y1, x2, y2, x3, y3] : ans)
    {
        std::cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << " " << x3 + 1 << " " << y3 + 1 << "\n";
        b[x1][y1] = '1' + '0' - b[x1][y1];
        b[x2][y2] = '1' + '0' - b[x2][y2];
        b[x3][y3] = '1' + '0' - b[x3][y3];
    }

    if (n == m and n == 2)
        print(b);
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