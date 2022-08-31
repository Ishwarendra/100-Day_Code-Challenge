#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<int> b(1, a[0]);

    constexpr int inf = 1e9;
    int max = -inf, min = inf;

    for (int i = 1; i < n; i++)
    {
        if (i < n - 1)
        {
            if (a[i - 1] <= a[i] and a[i] <= a[i + 1]
                    or a[i - 1] >= a[i] and a[i] >= a[i + 1])
                continue;
            
            b.emplace_back(a[i]);
        }
        else
            b.emplace_back(a[i]);
    }

    std::cout << std::size(b) << "\n";
    for (int i : b)
        std::cout << i << " ";
    std::cout << "\n";
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