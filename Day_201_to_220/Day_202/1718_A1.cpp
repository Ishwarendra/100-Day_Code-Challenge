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

    std::vector<int> a(n + 1), pref(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
    }

    constexpr int inf = 1e9;
    std::vector<int> dp(n + 1);

    std::map<int, std::vector<int>> m;
    m[0].emplace_back(0);

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + (a[i] != 0);
        int sz = std::size(m[pref[i]]);
        for (int id = sz - 1; id >= std::max(0, sz - 100); id--)
        {
            int j = m[pref[i]][id];
            int len = i - j;
            dp[i] = std::min(dp[i], len - 1 + dp[j]);
        }

        m[pref[i]].emplace_back(i);
    }

    std::cout << dp[n] << "\n";
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