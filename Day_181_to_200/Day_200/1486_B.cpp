#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    constexpr int inf = 1e9;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> y[i];

    std::sort(std::begin(x), std::end(x));
    std::sort(std::begin(y), std::end(y));

    i64 ans = 1;

    if (n % 2 == 0)
    {
        // 1, :2:, :3:, 4
        // auto [x1, _1] = a[n / 2 - 1];
        // auto [x2, _2] = a[n / 2];

        // auto [y1, __] = b[n / 2 - 1];
        // auto [y2, _] = b[n / 2];
        int x1 = x[n / 2 - 1];
        int x2 = x[n / 2];

        int y1 = y[n / 2 - 1];
        int y2 = y[n / 2];

        // print(x1, y1, x2, y2, n / 2, n / 2 + 1)

        ans += 1LL * (x2 - x1 + 1) * (y2 - y1 + 1);
        ans -= 1;
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