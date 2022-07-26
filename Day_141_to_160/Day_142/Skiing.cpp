#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

std::vector<std::vector<int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m)), vals;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            std::cin >> a[i][j];
            vals.push_back({a[i][j], i, j});
        }

    std::sort(vals.begin(), vals.end(), std::greater<std::vector<int>>());
    std::vector<std::vector<int>> vis(n, std::vector<int>(m));

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    auto bfs = [&](int i, int j, int cur_val)
    {
        std::queue<std::pair<int, int>> q;
        q.emplace(i, j);
        vis[i][j] = 1;

        while (!q.empty())
        {
            std::tie(i, j) = q.front();
            q.pop();

            for (auto dir : dirs)
            {
                int x = i + dir[0], y = j + dir[1];

                if (safe(x, y) and !vis[x][y] and a[x][y] <= a[i][j])
                    vis[x][y] = 1, q.emplace(x, y); 
            }
        }
    };

    int ans = 0;

    for (auto it : vals)
    {
        if (vis[it[1]][it[2]])
            continue;
        ans++;
        bfs(it[1], it[2], a[it[1]][it[2]]);
    }

    std::cout << ans << "\n";
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