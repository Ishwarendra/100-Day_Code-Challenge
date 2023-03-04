#include "bits/stdc++.h"

#undef LOCAL

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;
template <class T>
using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

std::vector<std::array<int, 2>> dirs {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
constexpr int inf = 1e9;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    std::function<bool(int, int)> bound = [&](int i, int j)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    };

    minHeap<std::array<int, 3>> pq;
    std::vector<std::vector<int>> vis(n, std::vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        pq.push({a[i][0], i, 0});
        pq.push({a[i][m - 1], i, m - 1});
        vis[i][m - 1] = 1;
        vis[i][0] = 1;
    }

    for (int j = 1; j < m - 1; j++)
    {
        pq.push({a[0][j], 0, j});
        pq.push({a[n - 1][j], n - 1, j});
        vis[0][j] = 1;
        vis[n - 1][j] = 1;
    }

    for (auto x : vis)
        print(x)

    long long ans = 0;

    while (!pq.empty())
    {
        auto cur = pq.top();
        int min = cur[0], x = cur[1], y = cur[2];
        pq.pop();

        for (auto [dx, dy] : dirs)
        {
            if (!bound(x + dx, y + dy))
                continue;
            if (vis[x + dx][y + dy])
                continue;

            x += dx;
            y += dy;

            pq.push({std::max(min, a[x][y]), x, y});
            ans += std::max(min, a[x][y]) - a[x][y];
            print(x-dx, y-dy, x, y, min, a[x][y])
            vis[x][y] = 1;

            x -= dx;
            y -= dy;
        }
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