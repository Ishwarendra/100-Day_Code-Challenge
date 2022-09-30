#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int ans = inf;
    std::function<void(int, int, int)> f;
    f = [&](int i, int x_, int cur_ans)
    {
        if (i == n)
        {
            if (std::is_sorted(std::begin(a), std::end(a)))
                ans = std::min(ans, cur_ans);
            return;
        }

        f(i + 1, x_, cur_ans);

        if (a[i] > x_)
        {
            int old = a[i];
            a[i] = x_;
            f(i + 1, old, cur_ans + 1);
            a[i] = old;
        }
    };

    f(0, x, 0);
    std::cout << (ans == inf ? -1 : ans) << "\n";
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