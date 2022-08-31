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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    std::vector dp(n, std::vector<i64>(400, inf));

    for (int i = 1; i < 400; i++)
        dp[0][i] = std::abs(a[0] - i);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < 400; j++)
        {
            for (int k = 1; k < j; k++)
            {
                assert(i < n and j < 400 and j - k >= 0);
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - k] + std::abs(a[i] - j));
            }
        }
    }

    i64 ans = inf;

    for (int i = 1; i < 400; i++)
        ans = std::min(ans, dp[n - 1][i]);

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