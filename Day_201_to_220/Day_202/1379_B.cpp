#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int l, r;
    i64 m;
    std::cin >> l >> r >> m;

    auto between = [&](int a)
    {
        return l <= a and a <= r;
    };

    for (int a = l; a <= r; a++)
    {
        int x = m % a;
        int b = r;
        int c = r - x;

        if (between(b) and between(c) and (m - b + c) / a > 0)
        {
            std::cout << a << " " << b << " " << c << "\n";
            return;
        }

        x = std::abs(m % a - a);
        c = r, b = r - x;
        if (between(b) and between(c) and (m - b + c) / a > 0)
        {
            std::cout << a << " " << b << " " << c << "\n";
            return;
        }
    }
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