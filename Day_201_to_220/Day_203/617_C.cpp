#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;

    std::vector<std::pair<int, int>> a(n);
    for (auto &[x, y] : a)
        std::cin >> x >> y;

    auto edist = [](std::pair<int, int> &x, int x1, int y1)
    {
        return (1LL * (x.first) - x1) * (1LL * (x.first) - x1) + (1LL * x.second - y1) * (1LL * x.second - y1); 
    };

    i64 ans = 0;

    for (int i = 0; i < n; ++i)
        ans = std::max(ans, edist(a[i], x2, y2));

    for (int i = 0; i < n; i++)
    {
        i64 d1 = edist(a[i], x1, y1);
        std::vector<int> vis(n);

        i64 max = 0;

        for (int j = 0; j < n; j++)
        {
            if (edist(a[j], x1, y1) <= d1)
                vis[j] = 1;
        }

        for (int j = 0; j < n; ++j)
        {
            if (vis[j])
                continue;

            max = std::max(max, edist(a[j], x2, y2));
        }

        ans = std::min(ans, max + d1);
    }

    std::cout << ans;

    return 0;
}