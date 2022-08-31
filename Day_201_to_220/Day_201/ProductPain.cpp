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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto f = [&](int i, int j, int k) -> i64
    {
        return 1LL * std::abs(a[i] - a[j]) * std::abs(a[j] - a[k]);
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 2; k < n; k++)
        {
            if (k == i + 2)
                ans += f(i, i + 1, i + 2);
            else
            {
                auto it = std::upper_bound(std::begin(a) + i + 1, std::begin(a) + k, (a[i] + a[k]) / 2);
                int j = it - std::begin(a);

                i64 op1 = 0;
                if (i != j and j != k)
                    op1 = f(i, j, k);
                i64 op2 = 0;
                if (i != j - 1 and j - 1 != k)
                    op2 = f(i, j - 1, k);

                ans += std::max(op1, op2);
            }
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