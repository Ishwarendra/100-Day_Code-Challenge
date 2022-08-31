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

    if (n == 1)
        std::cout << "1\n";
    else
    {
        std::vector<int> ans(n);
        if (n % 2)
            ans[0] = 1, ans[1] = 3, ans[2] = 2;
        else
            ans[0] = 2, ans[1] = 1;

        for (int i = 2 + n % 2, cur = 3 + n % 2; i < n - 1; i += 2)
            ans[i] = cur + 1, ans[i + 1] = cur, cur += 2;

        for (int i = 0; i < n; ++i)
            std::cout << ans[i] << " \n"[i + 1 == n];
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