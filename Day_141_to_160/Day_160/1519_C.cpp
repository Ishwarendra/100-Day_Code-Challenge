#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> ans(n + 1);

    std::vector<std::vector<int>> a(n);
    std::vector<int> u(n);
    for (int i = 0; i < n; ++i)
        std::cin >> u[i];

    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        a[--u[i]].push_back(x);
    }

    for (auto &p : a)
    {
        std::sort(std::begin(p), std::end(p), std::greater());

        int m = std::size(p);
        std::vector<i64> pref(m + 1);
        for (int i = 0; i < m; i++)
            pref[i + 1] = pref[i] + p[i];

        for (int i = 1; i <= m; ++i)
            ans[i] += pref[m - m % i];
    }

    for (int i = 1; i <= n; i++)
        std::cout << ans[i] << " \n"[i == n];
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